/*
 * gnc-hooks.h -- helpers for using Glib hook functions
 * Copyright (C) 2005 David Hampton <hampton@employees.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, contact:
 *
 * Free Software Foundation           Voice:  +1-617-542-5942
 * 59 Temple Place - Suite 330        Fax:    +1-617-542-2652
 * Boston, MA  02111-1307,  USA       gnu@gnu.org
 *
 */

void gnc_run_c_hook(const gchar *name, gpointer data);
void gnc_add_to_c_hook(const gchar *name, GHookFunc callback);
void gnc_remove_from_c_hook(const gchar *name, GHookFunc callback);


/* Common hook name */
#define HOOK_STARTUP		"hook_startup"
#define HOOK_SHUTDOWN		"hook_shutdown"
#define HOOK_UI_STARTUP		"ui-startup-hook"
#define HOOK_UI_POST_STARTUP	"hook_ui_post_startup"
#define HOOK_UI_SHUTDOWN	"hook_ui_shutdown"
#define HOOK_NEW_BOOK		"new-book-hook"
#define HOOK_REPORT		"report-hook"

/* Common session hook names */
#define HOOK_BOOK_OPENED	"book-opened-hook"
#define HOOK_BOOK_CLOSED	"book-closed-hook"
