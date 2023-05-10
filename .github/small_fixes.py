import os
import re

from file import File, FileType
from typing import Tuple, Callable, List

PatchFunc = Callable[[str], str]
Patch = Tuple[re.Pattern, PatchFunc]


def remove_spaces(match: str) -> str:
    return match.replace(' ', '')


def remove_last(match: str) -> str:
    return ';'


PATCHES: List[Patch] = [
    (re.compile(r"(\w+\s+\+{2})"), remove_spaces),
    (re.compile(r"(\+{2}\s+\w+)"), remove_spaces),
    (re.compile(r"(;{2})"), remove_last)
]


def main():
    for directory, _sub_folders, files in os.walk('.'):
        for filename in files:
            filename, ext = os.path.splitext(filename)
            file = File(directory, filename, ext[1::])

            if file.type != FileType.SOURCE:
                continue

            file_content = file.read()
            for pattern, patcher in PATCHES:
                for match in re.finditer(pattern, file_content):
                    group = str(match.group())
                    file_content = file_content.replace(group, patcher(group))

            with open(file.path, 'w') as f:
                f.write(file_content)


if __name__ == '__main__':
    main()
