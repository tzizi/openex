#ifndef __OX_WINDOW_GLOBALS_HPP__
#define __OX_WINDOW_GLOBALS_HPP__


#include <string>

struct SDL_Window;
struct ox_window_globals_t
{
  int width, height;
  SDL_Window* window;
  std::string title;
};

extern ox_window_globals_t ox_window_globals;


#endif
