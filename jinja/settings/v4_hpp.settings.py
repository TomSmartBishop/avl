# -*- coding: utf-8 -*-
from jinja_settings import *

IGNORE_JINJA_TEMPLATES = [
]

EXTRA_VARIABLES = {
    'filename': 'v4',
    'vecPar': 'v4',
    'scalarPar': 'sc',
    'dim': 4,
    'param': [ 'x', 'y', 'z', 'w'],
    'filetype': 'hpp'
}
EXTRA_VARIABLES.update(TYPE_INFO)

OUTPUT_OPTIONS = {
    'extension': '4.hpp',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = GLOBAL_JINJA_ENVIRONMENT