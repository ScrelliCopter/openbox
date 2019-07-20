set(TARGET obrender)

set(RR_MAJOR_VERSION 3)
set(RR_MINOR_VERSION 6)
set(RR_MICRO_VERSION 32)
configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/version.h)

set(INCLUDE_DIRS
	${CMAKE_SOURCE_DIR}
	${CMAKE_BINARY_DIR}
	${PANGO_INCLUDE_DIRS}
	${IMLIB2_INCLUDE_DIRS}
	${LIBRSVG_INCLUDE_DIRS})

set(SOURCE
	${CMAKE_SOURCE_DIR}/gettext.h
	${CMAKE_CURRENT_BINARY_DIR}/version.h
	button.c
	color.h
	color.c
	font.h
	font.c
	geom.h
	gradient.h
	gradient.c
	icon.h
	image.h
	image.c
	imagecache.h
	imagecache.c
	instance.h
	instance.c
	mask.h
	mask.c
	render.h
	render.c
	theme.h
	theme.c)

add_library(${TARGET} SHARED ${SOURCE})
target_compile_definitions(${TARGET} PRIVATE DEFAULT_THEME=\"${DEFAULT_THEME}\")
if (IMLIB2_FOUND)
	target_compile_definitions(${TARGET} PRIVATE USE_IMLIB2)
endif()
if (LIBRSVG_FOUND)
	target_compile_definitions(${TARGET} PRIVATE USE_LIBRSVG)
endif()
target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIRS})
#target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
