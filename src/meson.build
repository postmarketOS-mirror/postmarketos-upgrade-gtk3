postmarketos_upgrade_sources = [
  'main.c',
  'postmarketos_upgrade-window.c',
]

postmarketos_upgrade_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
  dependency('libhandy-0.0', version: '>= 0.0.12'),
]

gnome = import('gnome')

postmarketos_upgrade_sources += gnome.compile_resources('postmarketos_upgrade-resources',
  'postmarketos_upgrade.gresource.xml',
  c_name: 'postmarketos_upgrade'
)

executable('postmarketos-upgrade', postmarketos_upgrade_sources,
  dependencies: postmarketos_upgrade_deps,
  install: true,
)
