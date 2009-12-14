/* -*- indent-tabs-mode: nil; tab-width: 4; c-basic-offset: 4; -*-

   menuframe.h for the Openbox window manager
   Copyright (c) 2006        Mikael Magnusson
   Copyright (c) 2003-2007   Dana Jansens

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   See the COPYING file for a copy of the GNU General Public License.
*/

#ifndef ob__menuframe_h
#define ob__menuframe_h

#include "geom.h"
#include "window.h"
#include "render/render.h"

#include <glib.h>

struct _ObClient;
struct _ObMenu;
struct _ObMenuEntry;

typedef struct _ObMenuFrame ObMenuFrame;
typedef struct _ObMenuEntryFrame ObMenuEntryFrame;

extern GList *menu_frame_visible;

struct _ObMenuFrame
{
    /* stuff to be an ObWindow */
    Window_InternalType type;
    Window window;

    struct _ObMenu *menu;

    /* The client that the visual instance of the menu is associated with for
       its actions */
    struct _ObClient *client;

    ObMenuFrame *parent;
    ObMenuEntryFrame *parent_entry;
    ObMenuFrame *child;

    GList *entries;
    ObMenuEntryFrame *selected;
    /* if a submenu was selected, then this holds the entry for that submenu
       until it is closed */
    ObMenuEntryFrame *open_submenu;

    /* show entries from the menu starting at this index */
    guint show_from;

    /* If the submenus are being drawn to the right or the left */
    gboolean direction_right;

    /* On-screen area (including borders!) */
    Rect area;
    Strut item_margin;
    gint inner_w; /* inside the borders */
    gint item_h;  /* height of all normal items */
    gint text_x;  /* offset at which the text appears in the items */
    gint text_w;  /* width of the text area in the items */
    gint text_h;  /* height of the items */

    gint monitor; /* monitor on which to show the menu in xinerama */

    /* We make a copy of this for each menu, so that we don't have to re-render
       the background of the entire menu each time we render an item inside it.
    */
    RrAppearance *a_items;

    gboolean got_press; /* don't allow a KeyRelease event to run things in the
                           menu until it has seen a KeyPress.  this is to
                           avoid having the keybinding used to show the menu
                           end up running something inside the menu */
};

struct _ObMenuEntryFrame
{
    struct _ObMenuEntry *entry;
    ObMenuFrame *frame;

    guint ignore_enters;

    Rect area;
    gint border;

    Window window;
    Window icon;
    Window text;
    Window bullet;
};

extern GHashTable *menu_frame_map;

void menu_frame_startup(gboolean reconfig);
void menu_frame_shutdown(gboolean reconfig);

ObMenuFrame* menu_frame_new(struct _ObMenu *menu,
                            guint show_from,
                            struct _ObClient *client);
void menu_frame_free(ObMenuFrame *self);

void menu_frame_move(ObMenuFrame *self, gint x, gint y);
void menu_frame_move_on_screen(ObMenuFrame *self, gint x, gint y,
                               gint *dx, gint *dy);

gboolean menu_frame_show_topmenu(ObMenuFrame *self, gint x, gint y,
                                 gint button);
gboolean menu_frame_show_submenu(ObMenuFrame *self, ObMenuFrame *parent,
                                 ObMenuEntryFrame *parent_entry);

void menu_frame_hide_all();
void menu_frame_hide_all_client(struct _ObClient *client);

void menu_frame_render(ObMenuFrame *self);

void menu_frame_select(ObMenuFrame *self, ObMenuEntryFrame *entry,
                       gboolean immediate);
void menu_frame_select_previous(ObMenuFrame *self);
void menu_frame_select_next(ObMenuFrame *self);

ObMenuFrame* menu_frame_under(gint x, gint y);
ObMenuEntryFrame* menu_entry_frame_under(gint x, gint y);

void menu_entry_frame_show_submenu(ObMenuEntryFrame *self);

void menu_entry_frame_execute(ObMenuEntryFrame *self, guint state);

#endif
