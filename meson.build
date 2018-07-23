project('openex', 'cpp')

extra_args = ['-Wextra']

sdl = dependency('sdl2', required : host_machine.system() != 'windows')

if get_option('buildtype') == 'release'
  extra_args += '-DOX_BUILD_RELEASE'
else
  extra_args += '-DOX_BUILD_DEBUG'
endif

executable('openex', [
            'src/modules.cpp',

            'src/core/arg.cpp',
            'src/core/config.cpp',
            'src/core/core.cpp',
            'src/core/globals.cpp',
            'src/core/log.cpp',
            'src/core/main.cpp',
            'src/core/modules.cpp',

            'src/window/globals.cpp',
            'src/window/window.cpp'
          ],
           cpp_args: extra_args,
           dependencies: sdl)
