/* postmarketos_upgrade-window.h
 *
 * Copyright 2020 Martijn Braam
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <gtk/gtk.h>
#define HANDY_USE_UNSTABLE_API
#include <handy.h>
#include <stdio.h>

G_BEGIN_DECLS

#define POSTMARKETOS_UPGRADE_TYPE_WINDOW (postmarketos_upgrade_window_get_type())

G_DECLARE_FINAL_TYPE (PostmarketosUpgradeWindow, postmarketos_upgrade_window, POSTMARKETOS_UPGRADE, WINDOW, GtkApplicationWindow)

G_END_DECLS
