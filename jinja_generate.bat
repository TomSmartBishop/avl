jinja2_standalone_compiler inc --settings=jinja/v_h.settings.py
jinja2_standalone_compiler inc --settings=jinja/v_inl.settings.py
jinja2_standalone_compiler inc --settings=jinja/v2_h.settings.py
jinja2_standalone_compiler inc --settings=jinja/v2_inl.settings.py
jinja2_standalone_compiler inc --settings=jinja/v3_h.settings.py
jinja2_standalone_compiler inc --settings=jinja/v3_inl.settings.py
jinja2_standalone_compiler inc --settings=jinja/v4_h.settings.py
jinja2_standalone_compiler inc --settings=jinja/v4_inl.settings.py

jinja2_standalone_compiler test --settings=jinja/test_v2float_cpp.settings.py
jinja2_standalone_compiler test --settings=jinja/test_v3float_cpp.settings.py
jinja2_standalone_compiler test --settings=jinja/test_v4float_cpp.settings.py

jinja2_standalone_compiler test --settings=jinja/test_v2float_arr_cpp.settings.py
jinja2_standalone_compiler test --settings=jinja/test_v3float_arr_cpp.settings.py
jinja2_standalone_compiler test --settings=jinja/test_v4float_arr_cpp.settings.py
