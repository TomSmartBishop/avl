# -*- coding: utf-8 -*-
from jinja_settings import *

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'name': 'v',
    'dim': 0,
    'type': 'h',
    'param': [ 'x', 'y'] #temp
}
EXTRA_VARIABLES.update(TYPE_INFO)

OUTPUT_OPTIONS = {
    'extension': '.h',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = GLOBAL_JINJA_ENVIRONMENT