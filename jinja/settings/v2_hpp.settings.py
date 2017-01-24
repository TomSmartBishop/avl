# -*- coding: utf-8 -*-
from jinja_settings import *

IGNORE_JINJA_TEMPLATES = [
]

EXTRA_VARIABLES = {
    'filename': 'v2',
    'vecPar': 'v2',
    'scalarPar': 'sc',
    'dim': 2,
    'param': [ 'x', 'y'],
    'filetype': 'hpp'
}
EXTRA_VARIABLES.update(TYPE_INFO)

OUTPUT_OPTIONS = {
    'extension': '2.hpp',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = GLOBAL_JINJA_ENVIRONMENT