# -*- coding: utf-8 -*-
from jinja_settings import *

IGNORE_JINJA_TEMPLATES = [
]

EXTRA_VARIABLES = {
    'filename': 'v3',
    'vecPar': 'v3',
    'scalarPar': 'sc',
    'dim': 3,
    'param': [ 'x', 'y', 'z'],
    'filetype': 'h'
}
EXTRA_VARIABLES.update(TYPE_INFO)

OUTPUT_OPTIONS = {
    'extension': '3.h',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = GLOBAL_JINJA_ENVIRONMENT