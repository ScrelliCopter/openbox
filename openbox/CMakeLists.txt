set(TARGET openbox)

set(INCLUDE_DIRS
	${CMAKE_SOURCE_DIR}
	${CMAKE_BINARY_DIR}
	${GLIB_INCLUDE_DIRS}
	${PANGO_INCLUDE_DIRS}
	${LIBXML_INCLUDE_DIRS}
	${X11_INCLUDE_DIRS}
	${STARTUPNOTIFY_INCLUDE_DIRS}
	${XCURSOR_INCLUDE_DIRS}
	${IMLIB2_INCLUDE_DIRS}
	${LIBRSVG_INCLUDE_DIRS})

set(LIBRARIES
	${GLIB_LIBRARIES}
	${PANGO_LIBRARIES}
	${LIBXML_LIBRARIES}
	${X11_LIBRARIES}
	${STARTUPNOTIFY_LIBRARIES}
	${XCURSOR_LIBRARIES}
	${IMLIB2_LIBRARIES}
	${LIBRSVG_LIBRARIES}
	obt obrender)

set(SOURCE
	${CMAKE_SOURCE_DIR}/gettext.h
	actions/all.c
	actions/all.h
	actions/addremovedesktop.c
	actions/breakchroot.c
	actions/close.c
	actions/cyclewindows.c
	actions/debug.c
	actions/decorations.c
	actions/desktop.c
	actions/dock.c
	actions/dockautohide.c
	actions/directionalwindows.c
	actions/execute.c
	actions/exit.c
	actions/focus.c
	actions/focustobottom.c
	actions/fullscreen.c
	actions/growtoedge.c
	actions/iconify.c
	actions/if.c
	actions/kill.c
	actions/layer.c
	actions/lower.c
	actions/maximize.c
	actions/move.c
	actions/moverelative.c
	actions/moveresizeto.c
	actions/movetoedge.c
	actions/omnipresent.c
	actions/raise.c
	actions/raiselower.c
	actions/reconfigure.c
	actions/resize.c
	actions/resizerelative.c
	actions/restart.c
	actions/shade.c
	actions/shadelowerraise.c
	actions/showdesktop.c
	actions/showmenu.c
	actions/unfocus.c
	actions.c
	actions.h
	client.c
	client.h
	client_list_menu.c
	client_list_menu.h
	client_list_combined_menu.c
	client_list_combined_menu.h
	client_menu.c
	client_menu.h
	config.c
	config.h
	debug.c
	debug.h
	dock.c
	dock.h
	event.c
	event.h
	focus.c
	focus.h
	focus_cycle.c
	focus_cycle.h
	focus_cycle_indicator.c
	focus_cycle_indicator.h
	focus_cycle_popup.c
	focus_cycle_popup.h
	frame.c
	frame.h
	framerender.c
	framerender.h
	geom.h
	grab.c
	grab.h
	group.c
	group.h
	keyboard.c
	keyboard.h
	keytree.c
	keytree.h
	menuframe.c
	menuframe.h
	menu.c
	menu.h
	misc.h
	mouse.c
	mouse.h
	moveresize.c
	moveresize.h
	mwm.h
	openbox.c
	openbox.h
	ping.c
	ping.h
	place.c
	place.h
	place_overlap.c
	place_overlap.h
	prompt.c
	prompt.h
	popup.c
	popup.h
	resist.c
	resist.h
	screen.c
	screen.h
	session.c
	session.h
	stacking.c
	stacking.h
	startupnotify.c
	startupnotify.h
	translate.c
	translate.h
	window.c
	window.h)

add_executable(${TARGET} ${SOURCE})
target_compile_definitions(${TARGET} PRIVATE LOCALEDIR=\"${LOCALEDIR}\")
if (STARTUPNOTIFY_FOUND)
	target_compile_definitions(${TARGET} PRIVATE USE_LIBSN)
endif()
if (XCURSOR_FOUND)
	target_compile_definitions(${TARGET} PRIVATE USE_XCURSOR)
endif()
if (IMLIB2_FOUND)
	target_compile_definitions(${TARGET} PRIVATE USE_IMLIB2)
endif()
if (LIBRSVG_FOUND)
	target_compile_definitions(${TARGET} PRIVATE USE_LIBRSVG)
endif()
target_include_directories(${TARGET} PRIVATE ${INCLUDE_DIRS})
target_link_libraries(${TARGET} PRIVATE ${LIBRARIES})
