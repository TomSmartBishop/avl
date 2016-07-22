# -*- coding: utf-8 -*-

# Which templates don't you want to generate? (You can use regular expressions here!)
# Use strings (with single or double quotes), and separate each template/regex in a line terminated with a comma.
IGNORE_JINJA_TEMPLATES = [
    '.*base.jinja',
    '.*tests/.*'
]


# Do you have any additional variables to the templates? Put 'em here! (use dictionary ('key': value) format)
EXTRA_VARIABLES = {
    'name': 'v4',
    'dim': 4,
	'param': [ 'x', 'y', 'z', 'w']
}

OUTPUT_OPTIONS = {
    'extension': '4.h', # Including leading '.', example '.html'
    'remove_double_extension': True
}
