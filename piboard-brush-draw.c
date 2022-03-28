#include <gtk/gtk.h>
#include <mypaint-brush.h>
#include <mypaint-fixed-tiled-surface.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>

#define DEFAULT_PRESSURE        0.5

int     debug = 0;

/*
/usr/share/mypaint-data/1.0/brushes/classic/kabura.myb
*/
#define BRUSH_DEFAULT     "{" \
                          "\"comment\": \"MyPaint brush file\", " \
                          "\"group\": \"\", " \
                          "\"parent_brush_name\": \"classic/kabura\", " \
                          "\"settings\": {" \
                          "    \"anti_aliasing\": {" \
                          "        \"base_value\": 0.93, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"change_color_h\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"change_color_hsl_s\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"change_color_hsv_s\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"change_color_l\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"change_color_v\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"color_h\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"color_s\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"color_v\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"colorize\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"custom_input\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"custom_input_slowness\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"dabs_per_actual_radius\": {" \
                          "        \"base_value\": 2.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"dabs_per_basic_radius\": {" \
                          "        \"base_value\": 3.24, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"dabs_per_second\": {" \
                          "        \"base_value\": 48.87, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"direction_filter\": {" \
                          "        \"base_value\": 2.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"elliptical_dab_angle\": {" \
                          "        \"base_value\": 90.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"elliptical_dab_ratio\": {" \
                          "        \"base_value\": 1.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"eraser\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"hardness\": {" \
                          "        \"base_value\": 0.43, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"lock_alpha\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"offset_by_random\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"offset_by_speed\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"offset_by_speed_slowness\": {" \
                          "        \"base_value\": 1.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"opaque\": {" \
                          "        \"base_value\": 1.29, " \
                          "        \"inputs\": {" \
                          "            \"pressure\": [" \
                          "                [" \
                          "                  0.0, " \
                          "                  -0.989583" \
                          "                ], " \
                          "                [" \
                          "                  0.38253, " \
                          "                  -0.59375" \
                          "                ], " \
                          "                [" \
                          "                  0.656627, " \
                          "                  0.041667" \
                          "                ], " \
                          "                [" \
                          "                  1.0, " \
                          "                  1.0" \
                          "                ]" \
                          "            ]" \
                          "        }" \
                          "    }, " \
                          "    \"opaque_linearize\": {" \
                          "        \"base_value\": 0.29, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"opaque_multiply\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {" \
                          "            \"pressure\": [" \
                          "                [" \
                          "                  0.0, " \
                          "                  0.0" \
                          "                ], " \
                          "                [" \
                          "                  0.015, " \
                          "                  0.0" \
                          "                ], " \
                          "                [" \
                          "                  0.069277, " \
                          "                  0.9375" \
                          "                ], " \
                          "                [" \
                          "                  0.25, " \
                          "                  1.0" \
                          "                ], " \
                          "                [" \
                          "                  1.0, " \
                          "                  1.0" \
                          "                ]" \
                          "            ]" \
                          "        }" \
                          "    }, " \
                          "    \"radius_by_random\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"radius_logarithmic\": {" \
                          "        \"base_value\": 0.92, " \
                          "        \"inputs\": {" \
                          "            \"pressure\": [" \
                          "                [" \
                          "                  0.0, " \
                          "                  -0.7875" \
                          "                ], " \
                          "                [" \
                          "                  0.237952, " \
                          "                  -0.6" \
                          "                ], " \
                          "                [" \
                          "                  0.5, " \
                          "                  -0.15" \
                          "                ], " \
                          "                [" \
                          "                  0.76506, " \
                          "                  0.6" \
                          "                ], " \
                          "                [" \
                          "                  1.0, " \
                          "                  0.9" \
                          "                ]" \
                          "            ]" \
                          "        }" \
                          "    }, " \
                          "    \"restore_color\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"slow_tracking\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"slow_tracking_per_dab\": {" \
                          "        \"base_value\": 10.0, " \
                          "        \"inputs\": {" \
                          "            \"speed1\": [" \
                          "                [" \
                          "                  0.0, " \
                          "                  -1.428571" \
                          "                ], " \
                          "                [" \
                          "                  4.0, " \
                          "                  10.0" \
                          "                ]" \
                          "            ], " \
                          "            \"speed2\": [" \
                          "                [" \
                          "                  0.0, " \
                          "                  -1.428571" \
                          "                ], " \
                          "                [" \
                          "                  4.0, " \
                          "                  10.0" \
                          "                ]" \
                          "            ]" \
                          "        }" \
                          "    }, " \
                          "    \"smudge\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"smudge_length\": {" \
                          "        \"base_value\": 0.5, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"smudge_radius_log\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"speed1_gamma\": {" \
                          "        \"base_value\": 2.87, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"speed1_slowness\": {" \
                          "        \"base_value\": 0.04, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"speed2_gamma\": {" \
                          "        \"base_value\": 4.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"speed2_slowness\": {" \
                          "        \"base_value\": 0.8, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"stroke_duration_logarithmic\": {" \
                          "        \"base_value\": 4.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"stroke_holdtime\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"stroke_threshold\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }, " \
                          "    \"tracking_noise\": {" \
                          "        \"base_value\": 0.0, " \
                          "        \"inputs\": {}" \
                          "    }" \
                          "}, " \
                          "\"version\": 3" \
                          "}"
/*
 * motion是通过捕获GdkEventMotion事件而形成的，用于LibMyPaint进行绘制使用。
 * int
 * mypaint_brush_stroke_to (MyPaintBrush *self,,
 *                          MyPaintSurface *surface,,
 *                          float x,
 *                          float y,
 *                          float pressure,
 *                          float xtilt,
 *                          float ytilt,
 *                          double dtime);
 *
 * Motion的实现过程如下：
 * 1、按下鼠标时，将on_motion函数挂接在Drawing的motion-notify-event事件处理上，这样当有motion信号（鼠标移动时产生）时，会调用on_motion函数进行处理。
 * 2、开始一个MyPaintSurface的操作，函数为：
 * mypaint_surface_begin_atomic();
 * 3、同时将MyPaintBrush进行重置，创建新的笔画。调用的函数分别是：
 * mypaint_brush_reset();
 * mypaint_brush_new_stroke();
 * 4、在on_motion函数中，将motion信息输入到brush的笔画中，函数为：
 * mypaint_brush_stroke_to();
 * 5、当放开鼠标时，断开motion-nofify-event信号的处理函数on_motion。
 * 6、结束MyPaintSurface的操作。函数为：
 * mypaint_surface_end_atomic();
 * 7、通知gtk+进行绘图。
 */

static debug_out(const char *format, ...)
{
  time_t t;
  time(&t);
  struct tm* curtime = localtime(&t);
  char *buf = asctime(curtime);
  buf[strlen(buf) - 6] = ':';
  buf[strlen(buf) - 5] = ' ';
  buf[strlen(buf) - 4] = '\0';
  printf ("%s", buf);

  va_list ap;
  va_start(ap, format);
  printf(format, ap);
  va_end(ap);
  return 0;
}

static gboolean
on_motion(GtkWidget      *widget,
          GdkEventMotion *event,
          gpointer       data)
{
  if (debug)
    debug_out("enter function on_motion.\n");
  MyPaintSurface *surface = NULL;
  MyPaintBrush     *brush = NULL;
  static uint       ltime = 0;
  double           pressure;

  surface = (MyPaintSurface *)g_object_get_data (G_OBJECT(widget),
                                                 "surface");
  brush = (MyPaintBrush *)g_object_get_data (G_OBJECT(widget),
                                             "brush");
  if (!gdk_event_get_axis ((GdkEvent *)event,
                           GDK_AXIS_PRESSURE,
                           &pressure))
    pressure = DEFAULT_PRESSURE;
  if (surface
  && brush)
  {
    mypaint_brush_stroke_to (brush,
                             surface,
                             event->x,
                             event->y,
                             pressure,
                             0.0,
                             0.0,
                             ltime ? (event->time - ltime) / 1000 : 0);
    ltime = event->time;
  }
  if (debug)
    debug_out ("leave function on_motion.\n");
  return TRUE;
}

static gboolean
on_release (GtkWidget      *widget,
            GdkEventButton *event,
            gpointer       data)
{
  if (debug)
    debug_out ("enter function on_release.\n");
  MyPaintSurface *surface = NULL;
  MyPaintRectangle   *roi = NULL;

  g_signal_handlers_disconnect_by_func (widget,
                                        G_CALLBACK (on_motion),
                                        NULL);
  surface = (MyPaintSurface *)g_object_get_data (G_OBJECT(widget),
                                                 "surface");
  if (surface)
  {
    roi = (MyPaintRectangle *)g_malloc(sizeof (MyPaintRectangle));
    mypaint_surface_end_atomic(surface,
                               roi);
    if (debug > 1)
      debug_out ("finished a stroke.\n");
    gtk_widget_queue_draw_area(widget,
                               roi->x,
                               roi->y,
                               roi->width,
                               roi->height);
    g_free (roi);
  }
  if (debug)
    debug_out ("leave function on_release.\n");
  return TRUE;
}

static gboolean
on_press (GtkWidget      *widget,
          GdkEventButton *event,
          gpointer       data)
{
  if (debug)
    debug_out ("enter function on_press.\n");

  MyPaintSurface *surface = NULL;
  MyPaintBrush     *brush = NULL;

  g_signal_connect (widget,
                   "motion-notify-event",
                    G_CALLBACK (on_motion),
                    NULL);

  surface = (MyPaintSurface *)g_object_get_data (G_OBJECT(widget),
                                                 "surface");
  brush = (MyPaintBrush *)g_object_get_data (G_OBJECT(widget),
                                             "brush");
  if (surface)
  {
    mypaint_surface_begin_atomic(surface);
    if (debug > 1)
      debug_out ("begin a stroke.\n");
  }
  if (brush)
  {
    mypaint_brush_reset (brush);
    mypaint_brush_new_stroke (brush);
  }

  if (debug)
    debug_out ("leave function on_press.\n");
  return FALSE;
}

static gboolean
on_keyboard(GtkWidget   *widget,
            GdkEventKey *event,
            gpointer     data)
{
  if (debug)
    debug_out("enter function on_keyboard.\n");
  GtkWidget         *parent = NULL;

  switch (event->keyval)
  {
    case GDK_KEY_q:
         parent = gtk_widget_get_parent(widget);
         if (parent)
           gtk_widget_destroy(parent);
         break;
    default:
         break;
  }
  if (debug)
    debug_out("leave function on_keyboard.\n");
  return FALSE;
}

static gboolean
on_draw (GtkWidget  *widget,
         cairo_t    *cr,
         gpointer   data)
{
  if (debug)
    debug_out("enter function on_draw.\n");
  int width, height;
  int tile_size;
  int number_of_tile_rows;
  int tiles_per_rows;

  MyPaintTiledSurface *tiled_surface = NULL;
  tiled_surface = (MyPaintTiledSurface *)g_object_get_data (G_OBJECT(widget),
                                                            "surface");

  if (tiled_surface)
  {
    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);
    tile_size = tiled_surface->tile_size;
    number_of_tile_rows = ceil((float)height / tile_size);
    tiles_per_rows = ceil((float)width / tile_size);

    for (int tx = floor((double)tiled_surface->dirty_bbox.x  / tile_size); tx < ceil((double)(tiled_surface->dirty_bbox.x + tiled_surface->dirty_bbox.width) / tile_size); tx++)
      for (int ty = floor((double)tiled_surface->dirty_bbox.y / tile_size); ty < ceil((double)(tiled_surface->dirty_bbox.y + tiled_surface->dirty_bbox.height) / tile_size); ty++)
      {
        int max_x = tx < tiles_per_rows - 1 || width % tile_size == 0 ? tile_size : width % tile_size;
        int max_y = ty < number_of_tile_rows - 1 || height % tile_size == 0 ? tile_size : height % tile_size;
        MyPaintTileRequest request;
        mypaint_tile_request_init(&request, 0, tx, ty, TRUE);
        mypaint_tiled_surface_tile_request_start(tiled_surface, &request);
        for (int y = 0; y < max_y; y++)
          for (int x = 0; x < max_x; x++)
          {
            int xx = tx * tile_size + x;
            int yy = ty * tile_size + y;
            int offset = tile_size * y + x;
            uint16_t r = request.buffer[offset * 4] & 0x7FFF;
            uint16_t g = request.buffer[offset * 4 + 1] & 0x7FFF;
            uint16_t b = request.buffer[offset * 4 + 2] & 0x7FFF;
            float rr = (float)r / 0x7FFF;
            float gg = (float)g / 0x7FFF;
            float bb = (float)b / 0x7FFF;
          
            cairo_set_source_rgb(cr, rr, gg, bb);
            cairo_set_line_width (cr, 1);
            cairo_move_to(cr, xx, yy);
            cairo_line_to(cr, xx + 1, yy + 1);
            cairo_stroke(cr);
          }
        mypaint_tiled_surface_tile_request_end(tiled_surface, &request);
      }
    tiled_surface->dirty_bbox.x = 0;
    tiled_surface->dirty_bbox.y = 0;
    tiled_surface->dirty_bbox.width = 0;
    tiled_surface->dirty_bbox.height = 0;
  }
  if (debug)
    debug_out("leave function on_draw...\n");
  return FALSE;
}

static gboolean
in_focus(GtkWidget      *widget,
         GdkEventFocus  *event,
         gpointer       data)
{
  if (debug)
    debug_out ("enter function in_focus.\n");
  g_signal_connect (widget,
                    "draw",
                    G_CALLBACK (on_draw),
                    NULL);
  g_signal_connect (widget,
                   "button-press-event",
                   G_CALLBACK (on_press),
                   NULL);
  g_signal_connect (widget,
                   "button-release-event",
                   G_CALLBACK (on_release),
                   NULL);
  g_signal_connect (widget,
                   "key-press-event",
                   G_CALLBACK (on_keyboard),
                   NULL);
  if (debug)
    debug_out ("leave function in_focus.\n");
  return FALSE;
}

static gboolean
out_focus(GtkWidget      *widget,
          GdkEventFocus  *event,
          gpointer       data)
{
  if (debug)
    debug_out ("enter function out_focus.\n");
  g_signal_handlers_disconnect_by_func (widget,
                                        G_CALLBACK (on_draw),
                                        NULL);
  g_signal_handlers_disconnect_by_func (widget,
                                        G_CALLBACK (on_press),
                                        NULL);
  g_signal_handlers_disconnect_by_func (widget,
                                        G_CALLBACK (on_release),
                                        NULL);
  g_signal_handlers_disconnect_by_func (widget,
                                        G_CALLBACK (on_keyboard),
                                        NULL);
  if (debug)
    debug_out ("leave function out_focus.\n");
  return FALSE;
}

static gboolean
on_configure(GtkWidget         *widget,
             GdkEventConfigure *event,
             gpointer          data)
{
  if (debug)
    debug_out ("enter function on_configure.\n");
  static int  width = -1;
  static int height = -1;

  MyPaintSurface  *surface = NULL;
  surface = (MyPaintSurface *)g_object_get_data (G_OBJECT(widget),
                                                 "surface");
  if (event->width != width
  || event->height != height)
  {
    if (surface)
      mypaint_surface_unref (surface);
    surface = (MyPaintSurface *)mypaint_fixed_tiled_surface_new(event->width,
                                                                event->height);
    g_object_set_data (G_OBJECT(widget),
                       "surface",
                       surface);
    width = event->width;
    height = event->height;
  }
  if (debug)
    debug_out ("leave function on_configure.\n");
  return TRUE;
}

static void
on_close (GtkWidget *widget,
          gpointer  data)
{
  if (debug)
    debug_out ("enter function on_close.\n");
  MyPaintSurface *surface = NULL;
  MyPaintBrush     *brush = NULL;

  surface = (MyPaintSurface *)g_object_get_data (G_OBJECT(widget),
                                                 "surface");
  brush = (MyPaintBrush *)g_object_get_data (G_OBJECT(widget),
                                             "brush");
  if (surface)
    mypaint_surface_unref (surface);
  if (brush)
    mypaint_brush_unref (brush);
  if (debug)
    debug_out ("leave function on_close.\n");
}

static void
on_activate (GtkApplication *app,
             gpointer        data)
{
  if (debug)
    debug_out ("enter function on_activate.\n");
  GtkWidget *window = NULL;
  window = gtk_application_window_new (app);

  if (window)
  {
    gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_window_set_keep_above (GTK_WINDOW(window),
                               TRUE);
  }

  GtkWidget *drawing = NULL;
  drawing = gtk_drawing_area_new ();

  if (drawing)
  {
    gtk_widget_set_events (drawing,
                           gtk_widget_get_events(drawing)
                           | GDK_FOCUS_CHANGE_MASK
                           | GDK_BUTTON_PRESS_MASK
                           | GDK_BUTTON_RELEASE_MASK
                           | GDK_POINTER_MOTION_MASK);
    gtk_widget_set_can_focus (drawing,
                              TRUE);
    g_signal_connect (drawing,
                      "configure-event",
                      G_CALLBACK (on_configure),
                      NULL);
    g_signal_connect (drawing,
                      "destroy",
                      G_CALLBACK (on_close),
                      NULL);
    g_signal_connect (drawing,
                     "focus-in-event",
                     G_CALLBACK (in_focus),
                     NULL);
    g_signal_connect (drawing,
                     "focus-out-event",
                     G_CALLBACK (out_focus),
                     NULL);
  }

  MyPaintBrush  *brush = NULL;
  brush = mypaint_brush_new();
  if (brush)
  {
    mypaint_brush_from_string(brush,
                              BRUSH_DEFAULT);
    g_object_set_data (G_OBJECT(drawing),
                       "brush",
                       brush);
  }

  gtk_container_add (GTK_CONTAINER (window),
                     drawing);

  gtk_widget_show_all (window);
  if (debug)
    debug_out ("leave function on_activate.\n");
}

int
main (int    argc,
      char   **argv)
{
  GtkApplication *app = NULL;
  const GOptionEntry options[] = {
                                   {
                                     .long_name       = "debug",
                                     .short_name      = 'd',
                                     .flags           = G_OPTION_FLAG_NONE,
                                     .arg             = G_OPTION_ARG_INT,
                                     .arg_data        = &debug,
                                     .description     = "调试值",
                                     .arg_description = NULL,
                                   },
                                   {
                                     NULL,
                                   }
                                 };

  int status;

  app = gtk_application_new ("com.pi-classroom.piboard",
                             0);
  if (app)
  {
    g_signal_connect (app,
                      "activate",
                      G_CALLBACK (on_activate),
                      NULL);
    g_application_add_main_option_entries (G_APPLICATION (app),
                                           options);
    status = g_application_run (G_APPLICATION (app),
                                argc,
                                argv);
  }
  if (app)
    g_object_unref (app);

  return status;
}
