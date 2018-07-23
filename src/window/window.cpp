#include "window.hpp"
#include "window_inner.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


bool ox_window_init() {
  OX_LOGV("Initializing SDL");
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    OX_LOGE("Error initializing SDL");
    return false;
  }

  OX_LOGV("Creating window");
  ox_window_globals.window = SDL_CreateWindow(ox_window_globals.title.c_str(),
                                              SDL_WINDOWPOS_UNDEFINED,
                                              SDL_WINDOWPOS_UNDEFINED,
                                              ox_window_globals.width,
                                              ox_window_globals.height,
                                              SDL_WINDOW_OPENGL);

  if (!ox_window_globals.window) {
    OX_LOGE("Error creating window");
    return false;
  }

  SDL_Delay(3000);

  OX_LOGV("Destroying window");
  SDL_DestroyWindow(ox_window_globals.window);

  OX_LOGV("Cleaning up SDL");
  SDL_Quit();

  return true;
}

struct ox_module ox_window =
  {
   .name = "window",

   .init = ox_window_init,
   .config =
   {
    .params =
    (ox_config_param[]){
                        {
      .name = "title",
      .nicks = NULL,

      .type = "string",

      .value = "OpenEx",
      .help = "Title of the window",

      .variable = (void**)&ox_window_globals.title
     },
     {
      .name = "width",
      .nicks = (const char*[]){"w", NULL},

      .type = "int",

      .value = "800",
      .help = "Width of the window",

      .variable = (void**)&ox_window_globals.width
     },
     {
      .name = "height",
      .nicks = (const char*[]){"height", NULL},

      .type = "int",

      .value = "600",
      .help = "Height of the window",

      .variable = (void**)&ox_window_globals.height
     },
     OX_CONFIG_PARAM_END},

    .on_change = NULL
   }
  };
