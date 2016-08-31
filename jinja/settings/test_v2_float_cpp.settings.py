# -*- coding: utf-8 -*-
from jinja_settings import *

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'vecPar': 'v2',
    'scalarPar': 'sc',
    'dim': 2,
    'filetype': 'test',
    'param': [ 'x', 'y'], #temp
    'test_vecDef': 'vec2<float>',
    'test_scalarDef': 'float'
}
EXTRA_VARIABLES.update(TYPE_INFO)

OUTPUT_OPTIONS = {
    'extension': '2_float_test.cpp',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = GLOBAL_JINJA_ENVIRONMENT
