# -*- coding: utf-8 -*-
from jinja_settings import *

IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

EXTRA_VARIABLES = {
    'name': 'v3',
    'dim': 3,
    'type': 'test',
    'param': [ 'x', 'y', 'z'], #temp
    'test_vecDef': 'vec3<float>',
    'test_scalarDef': 'float'
}
EXTRA_VARIABLES.update(TYPE_INFO)

OUTPUT_OPTIONS = {
    'extension': '_test.cpp',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = GLOBAL_JINJA_ENVIRONMENT
