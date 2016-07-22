# -*- coding: utf-8 -*-

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'name': 'v2',
    'dim': 2,
    'param': [ 'x', 'y'],
    'type': 'h'
}

OUTPUT_OPTIONS = {
    'extension': '2.h',
    'remove_double_extension': False
}
