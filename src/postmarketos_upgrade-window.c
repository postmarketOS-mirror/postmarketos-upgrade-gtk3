/* postmarketos_upgrade-window.c
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

#include "postmarketos_upgrade-config.h"
#include "postmarketos_upgrade-window.h"

struct _PostmarketosUpgradeWindow
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
  GtkHeaderBar        *header_bar;
  GtkButton           *close_button;
  GtkLabel            *custom_text;
};

G_DEFINE_TYPE (PostmarketosUpgradeWindow, postmarketos_upgrade_window, GTK_TYPE_APPLICATION_WINDOW)

static void
postmarketos_upgrade_window_class_init (PostmarketosUpgradeWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/org/postmarketos/Upgrade/postmarketos_upgrade-window.ui");
  gtk_widget_class_bind_template_child (widget_class, PostmarketosUpgradeWindow, header_bar);
  gtk_widget_class_bind_template_child (widget_class, PostmarketosUpgradeWindow, close_button);
  gtk_widget_class_bind_template_child (widget_class, PostmarketosUpgradeWindow, custom_text);


}

static void
postmarketos_upgrade_window_init (PostmarketosUpgradeWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));

  FILE *f;
  f = fopen("/etc/upgrade-message", "r");
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *buff = malloc(fsize+1);
  fread(buff, 1, fsize, f);
  fclose(f);

  buff[fsize] = 0;

  gtk_label_set_markup(self->custom_text, buff);

  /* Remove from autostart (-f: ignore nonexistent) */
  system("rm -vf ~/.config/autostart/org.postmarketos.Upgrade.desktop");
}
