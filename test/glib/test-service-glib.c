/* -*- mode: C; c-file-style: "gnu" -*- */
#include "dbus-glib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static GMainLoop *loop;

int
main (int argc, char **argv)
{
  DBusConnection *connection;
  GError *error;
  int i;
  
  g_type_init ();
  
  loop = g_main_loop_new (NULL, FALSE);

  error = NULL;
  connection = dbus_bus_get_with_g_main (DBUS_BUS_ACTIVATION,
                                         &error);
  if (connection == NULL)
    {
      g_printerr ("Failed to open connection to bus: %s\n",
                  error->message);
      g_error_free (error);
      exit (1);
    }

  
  
  g_print ("Successfully completed %s\n", argv[0]);
  
  return 0;
}