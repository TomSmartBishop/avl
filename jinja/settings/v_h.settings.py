# -*- coding: utf-8 -*-
from jinja_settings import *

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'filename': 'v',
    'vecPar': 'v',
    'scalarPar': 'sc',
    'dim': 0,
    'filetype': 'h',
    'param': [ 'x', 'y'] #temp
}
EXTRA_VARIABLES.update(TYPE_INFO)

OUTPUT_OPTIONS = {
    'extension': '.h',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = GLOBAL_JINJA_ENVIRONMENT