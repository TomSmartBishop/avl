# -*- coding: utf-8 -*-

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'name': 'v',
    'dim': 0,
    'type': 'inl'
}

OUTPUT_OPTIONS = {
    'extension': '.inl',
    'remove_double_extension': False
}
