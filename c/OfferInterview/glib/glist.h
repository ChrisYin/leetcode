/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __G_LIST_H__
#define __G_LIST_H__

#include "glib.h"

typedef struct _GList GList;

struct _GList {
    ElementType data;
    GList *next;
    GList *prev;
};

/* Doubly linked lists
 */
GList *g_list_append                    (GList *list, ElementType data);

GList *g_list_prepend                   (GList *list, ElementType data);
 
GList *g_list_insert                    (GList *list, ElementType data, uint position);

GList *g_list_insert_before             (GList *list, GList *sibling, ElementType data);
 
GList *g_list_concat                    (GList *list1, GList *list2);

GList *g_list_remove                    (GList *list, ElementType data);

GList *g_list_remove_all                (GList *list, ElementType data);
 
GList *g_list_remove_link             (GList *list, GList *llink);

GList *g_list_delete_link             (GList *list, GList *link_);
 
GList *g_list_reverse                 (GList *list);

GList *g_list_copy                    (GList *list);

GList *g_list_nth                     (GList *list, uint n);

GList *g_list_nth_prev                (GList *list, uint n);
  
GList *g_list_find                    (GList *list, gconstpointer data);

GList *g_list_find_custom             (GList *list, gconstpointer data, GCompareFunc func);
  
uint g_list_position                (GList *list, GList *llink);

uint g_list_index                   (GList *list, gconstpointer data);
  
GList *g_list_last                    (GList *list);
  
GList * g_list_first                   (GList *list);
  
guint g_list_length                  (GList *list);
  
void g_list_foreach(GList *list, GFunc func, ElementType user_data);

  
ElementType g_list_nth_data                (GList *list, guint n);


#define g_list_previous(list)            ((list) ? (((GList *)(list))->prev) : NULL)
#define g_list_next(list)            ((list) ? (((GList *)(list))->next) : NULL)


#endif /* __G_LIST_H__ */
