project(
  'Matter',
  'c',
  'cpp',
  meson_version: '>= 1.3.0',
  version: '0.0.1_a',
  default_options: [
    'warning_level=3',
    'cpp_std=c++20',
  ],
)

inc_dir = include_directories('.', 'include')

configure_file(
  input: 'config.h.in',
  output: 'config.h',
  configuration: {
    'PROJECT_NAME': meson.project_name(),
    'PROJECT_VERSION': meson.project_version(),
    'PROJECT_DESCRIPTION': 'Project description',
    'PROJECT_BUG_ADDRESS': 'https://example.com',
  },
)

subdir('source')
