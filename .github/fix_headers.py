from __future__ import annotations

import os
from dataclasses import dataclass

from datetime import datetime
from enum import Enum, auto, StrEnum
from pathlib import Path
from typing import List, Final

PROJECT: Final[str] = "42sh"
YEAR: Final[int] = datetime.now().year
SENTINEL: Final[int] = -1
MAKEFILE_COMMENT: Final[str] = "##"


class CToken(StrEnum):
    BLOCK_COMMENT_START = "/*"
    BLOCK_COMMENT_END = "*/"


class FileType(Enum):
    SOURCE = auto()
    MAKEFILE = auto()
    OTHER = auto()

    @classmethod
    def from_file(cls, file: File):
        if file.ext == 'c' or file.ext == 'h':
            return cls.SOURCE

        if file.ext == 'mk' or file.name == 'Makefile':
            return cls.MAKEFILE

        return cls.OTHER


HEADERS = {
    FileType.SOURCE: Path(".github/templates/c.header").read_text(),
    FileType.MAKEFILE: Path(".github/templates/mk.header").read_text()
}


@dataclass
class File:
    dir: str
    name: str
    ext: str

    def __post_init__(self):
        self.type: FileType = FileType.from_file(self)

    @property
    def fullname(self):
        if not self.ext:
            return self.name

        return f"{self.name}.{self.ext}"

    @property
    def path(self):
        if not self.dir or self.dir == '.':
            return self.fullname

        return f"{self.dir}/{self.fullname}"

    def read(self):
        with open(self.path) as f:
            return f.read()

    def fix_header(self):
        header_template = HEADERS.get(self.type)

        if not header_template:
            return

        header = header_template.format(
            year=YEAR,
            filename=self.fullname,
            project=PROJECT
        )

        content = self.read()
        if content.startswith(header):
            return

        print("Formatting", self.path)
        lines = content.splitlines()
        lineno = get_first_code_line(self.type, lines)
        keep = '\n'.join(lines[lineno + 1:])

        with open(self.path, 'w') as f:
            f.write(f"{header}{keep}\n")


def get_first_code_line(file_type: FileType, lines: List[str]) -> int:
    start = get_first_non_empty_line(lines)
    line_count = len(lines)

    if start > line_count:
        return SENTINEL

    if file_type == FileType.SOURCE:
        if CToken.BLOCK_COMMENT_START not in lines[start]:
            return start

        while (
            start < line_count
            and CToken.BLOCK_COMMENT_END not in lines[start]
        ):
            start += 1
    else:
        if MAKEFILE_COMMENT not in lines[start]:
            return start

        while start < line_count and MAKEFILE_COMMENT in lines[start]:
            start += 1
        start -= 1

    return get_first_non_empty_line(lines, start + 1)


def get_first_non_empty_line(lines: List[str], from_id: int = 0) -> int:
    line_count = len(lines)

    if from_id >= line_count:
        return SENTINEL

    while lines[from_id].isspace():
        from_id += 1

    return from_id


def main():
    for directory, _sub_folders, files in os.walk('.'):
        for filename in files:
            filename, ext = os.path.splitext(filename)

            file = File(directory, filename, ext[1::])
            file.fix_header()


if __name__ == '__main__':
    main()
