project(
  'Matter',
  'c',
  'cpp',
  meson_version: '>= 1.3.0',
  version: '0.0.1-alpha',
  default_options: [
    'warning_level=3',
    'cpp_std=c++20',
  ],
)

configure_file(
  input: 'config.h.in',
  output: 'config.h',
  configuration: {
    'PROJECT_NAME': meson.project_name(),
    'PROJECT_VERSION': meson.project_version(),
    'PROJECT_DESCRIPTION': 'Wayland compositor',
    'PROJECT_BUG_ADDRESS': 'https://github.com/silitonix/matter/issus',
  },
)

inc_dir = include_directories('.', 'inc')
sources = run_command('find', 'src', '-type', 'f', '-name', '*[.cpp,.c]', check: false).stdout().strip().split('\n')

wayland_server_dep = dependency('wayland-server')
input_dep = dependency('libinput')
cz_louvre_dep = dependency('cz-louvre')
cz_core_dep = dependency('cz-core')
cz_skia_dep = dependency('cz-skia')
cz_ream_dep = dependency('cz-ream')
cz_kay_dep = dependency('cz-kay')
cz_srm_dep = dependency('cz-srm')
gl_dep = dependency('gl', version: '>= 1.2')
egl_dep = dependency('egl', version: '>=1.5')
xkbcommon_dep = dependency('xkbcommon', version: '>= 1.4.0')
libseat_dep = dependency('libseat', version: '>= 0.6.4')

dependencies = [
  cz_louvre_dep,
  cz_core_dep,
  cz_skia_dep,
  cz_srm_dep,
  cz_ream_dep,
  cz_kay_dep,
  wayland_server_dep,
  egl_dep,
  gl_dep,
  input_dep,
  xkbcommon_dep,
  libseat_dep,
]

executable(
  'matter',
  sources,
  include_directories: inc_dir,
  dependencies: dependencies,
  install: true,
)
