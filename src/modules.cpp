#include "core/module.hpp"

#include "core/core.hpp"
#include "window/window.hpp"

ox_module** ox_modules = (ox_module*[])
  {
   &ox_core,
   &ox_window,
   NULL
  };
