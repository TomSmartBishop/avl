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
    'dim': 2,
    'type': 'float',
    'suffix': 'f',
    'extends': '[2]'
}

OUTPUT_OPTIONS = {
    'extension': '2_arr.cpp', # Including leading '.', example '.html'
    'remove_double_extension': False
}
