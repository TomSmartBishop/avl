# -*- coding: utf-8 -*-

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'name': 'v2',
    'dim': 2,
    'param': [ 'x', 'y'],
    'type': 'inl'
}

OUTPUT_OPTIONS = {
    'extension': '2.inl',
    'remove_double_extension': False
}
