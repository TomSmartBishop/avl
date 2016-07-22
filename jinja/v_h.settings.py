# -*- coding: utf-8 -*-

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'name': 'v',
    'dim': 0,
    'type': 'h'
}

OUTPUT_OPTIONS = {
    'extension': '.h',
    'remove_double_extension': False
}
