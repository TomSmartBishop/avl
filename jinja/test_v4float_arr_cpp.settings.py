# -*- coding: utf-8 -*-

# Which templates don't you want to generate? (You can use regular expressions here!)
# Use strings (with single or double quotes), and separate each template/regex in a line terminated with a comma.
IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]

# Do you have any additional variables to the templates? Put 'em here! (use dictionary ('key': value) format)
EXTRA_VARIABLES = {
    'test_type': 'Array',
    'name': 'float',
    'dim': 4,
    'type': 'float',
    'suffix': 'f',
    'extends': '[4]'
}

OUTPUT_OPTIONS = {
    'extension': '4_arr.cpp', # Including leading '.', example '.html'
    'remove_double_extension': False
}
