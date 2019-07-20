set(TARGET obt)

set(INCLUDE_DIRS
	${CMAKE_SOURCE_DIR}
	${GLIB_INCLUDE_DIRS}
	${LIBXML_INCLUDE_DIRS})

set(SOURCE
	bsearch.h
	display.h
	display.c
	internal.h
	keyboard.h
	keyboard.c
	xml.h
	xml.c
	ddparse.h
	ddparse.c
	link.h
	link.c
	paths.h
	paths.c
	prop.h
	prop.c
	signal.h
	signal.c
	util.h
	xqueue.h
	xqueue.c)

add_library(${TARGET} ${SOURCE})
target_compile_definitions(${TARGET} PRIVATE DATADIR=\"${DATADIR}\" CONFIGDIR=\"${CONFIGDIR}\")
target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIRS})
