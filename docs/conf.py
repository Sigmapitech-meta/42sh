import subprocess

project = "42sh"
version = "1"

autodoc_member_order = "alphabetical"

extensions = [
    "sphinx_design",
    "sphinx.ext.napoleon",
    "sphinx.ext.autodoc",
    "sphinx.ext.intersphinx",
    "sphinxcontrib_trio",
    "sphinxcontrib.mermaid",
    # ↓ tests
    'sphinx.ext.doctest',
    'sphinx.ext.mathjax',
    'sphinx.ext.viewcode',
    'sphinx.ext.imgmath',
    'sphinx.ext.todo',
    'breathe',
]

subprocess.call("make clean", shell=True)
subprocess.call("doxygen Doxyfile", shell=True)

highlight_language = 'C'

breathe_projects = {"42sh": ".build/xml"}
breathe_default_project = "42sh"
breathe_default_members = ('members', 'undoc-members')

exclude_patterns = ['.build', 'Thumbs.db', '.DS_Store']

html_theme = "furo"
html_theme_options = {
    "light_css_variables": {
        "color-brand-primary": "#4C8CBF",
        "color-brand-content": "#306998",
        "color-admonition-background": "blue",
    },
    "dark_css_variables": {
        "color-brand-primary": "#306998",
        "color-brand-content": "#FFE871",
        "color-admonition-background": "yellow",
    },
    "sidebar_hide_name": True,
}

default_dark_mode = True

html_static_path = ["_static"]
html_css_files = ["custom.css"]
