sources = files(
  'global.cpp',
  'main.cpp',
)

wayland_server_dep = dependency('wayland-server')
libinput_dep = dependency('libinput')
cz_louvre_dep = dependency('cz-louvre')
cz_core_dep = dependency('cz-core')
cz_skia_dep = dependency('cz-skia')
cz_ream_dep = dependency('cz-ream')
cz_kay_dep = dependency('cz-kay')

dependencies = [
  wayland_server_dep,
  libinput_dep,
  cz_louvre_dep,
  cz_core_dep,
  cz_skia_dep,
  cz_ream_dep,
  cz_kay_dep,
]

executable(
  'matter',
  sources,
  include_directories: inc_dir,
  dependencies: dependencies,
  install: true,
)
