cmake_minimum_required(VERSION 3.14)
project(openbox
	VERSION 3.6.1
	HOMEPAGE_URL "https://github.com/ScrelliCopter/openbox"
	LANGUAGES C)

find_package(PkgConfig)
pkg_check_modules(GLIB REQUIRED glib-2.0>=2.14.0)
pkg_check_modules(PANGO REQUIRED pango>=1.8.0 pangoxft>=1.8.0)
pkg_check_modules(LIBXML REQUIRED libxml-2.0>=2.6.0)
pkg_check_modules(X11 REQUIRED x11)

set(DATADIR    ${CMAKE_INSTALL_PREFIX}/share)
set(SYSCONFDIR ${CMAKE_INSTALL_PREFIX}/etc)
set(THEMEDIR   ${DATADIR}/themes)
set(LOCALEDIR  ${DATADIR}/locale)
set(CONFIGDIR  ${SYSCONFDIR}/xdg)

set(DEFAULT_THEME Clearlooks)
configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/version.h)

add_subdirectory(obrender)
add_subdirectory(obt)
add_subdirectory(openbox)
