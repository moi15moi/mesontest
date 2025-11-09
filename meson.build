project(
    'MesonTest',
    'c',
    default_options: ['buildtype=release', 'python.allow_limited_api=false'],
    meson_version: '>=1.3.0',
    version: '0.2.1',
)

py = import('python').find_installation(pure: false)

if py.language_version().version_compare('>=3.12')
    message('limited_api is activated')
    limited_api_args = {'limited_api': '3.12'}
else
    message('limited_api is deactivated')
    limited_api_args = {}
endif

py.extension_module(
    'my_module',
    'my_module.c',
    install: true,
    kwargs: limited_api_args
)
