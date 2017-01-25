# -*- coding: utf-8 -*-
IGNORE_JINJA_TEMPLATES = [
]

EXTRA_VARIABLES = {
}

OUTPUT_OPTIONS = {
    'extension': '.cpp',
    'remove_double_extension': False
}

JINJA_ENVIRONMENT = {
    'BLOCK_START_STRING': '/*%',
    'BLOCK_END_STRING': '%*/',
    'VARIABLE_START_STRING': '$',
    'VARIABLE_END_STRING': '@',
    'COMMENT_START_STRING': '/*#',
    'COMMENT_END_STRING': '#*/',
    'LINE_STATEMENT_PREFIX': '//%',
    'LINE_COMMENT_PREFIX': '###',
#    'TRIM_BLOCKS': True, # Jinja default is False
#    'LSTRIP_BLOCKS': True, #Jinja default is False
#    'NEWLINE_SEQUENCE': '\n',
#    'KEEP_TRAILING_NEWLINE': False
}