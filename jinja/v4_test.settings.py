# -*- coding: utf-8 -*-
from jinja_settings import *

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'vecPar': 'v4',
    'scalarPar': 'sc',
    'dim': 4,
    'filetype': 'test',
    'param': [ 'x', 'y', 'z', 'w'], #temp
    'test_vecDef': 'vec4<float>',
    'test_scalarDef': 'float'
}
EXTRA_VARIABLES.update(TYPE_INFO)

OUTPUT_OPTIONS = {
    'extension': '4_float_test.cpp',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = GLOBAL_JINJA_ENVIRONMENT
