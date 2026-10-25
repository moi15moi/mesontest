project(
    'MesonTest',
    'cpp',
    default_options: ['cpp_std=c++17', 'buildtype=release', 'python.allow_limited_api=false'],
    meson_version: '>=1.3.0',
    version: '0.2.1',
)

cc = meson.get_compiler('cpp')
py = import('python').find_installation(pure: false)

nanobind_dep = dependency('nanobind')

if py.language_version().version_compare('>=3.12')
    message('limited_api is activated')
    limited_api_args = {'limited_api': '3.12'}
else
    message('limited_api is deactivated')
    limited_api_args = {}
endif

py.extension_module(
    'my_module',
    'my_module.cpp',
    install: true,
    dependencies : [nanobind_dep],
    kwargs: limited_api_args
)
