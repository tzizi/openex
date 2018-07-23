#include "core_inner.hpp"
#include "modules.hpp"


struct ox_module* ox_modules_get(std::string name)
{
  struct ox_module** module = ox_core_globals.modules;

  for (;*module; module++) {
    if (std::string((*module)->name) == name) {
      return *module;
    }
  }

  return NULL;
}


void ox_modules_init()
{
  struct ox_module** module = ox_core_globals.modules;

  for (;*module; module++) {
    if ((*module)->init) {
      if (!(*module)->init()) {
        OX_LOGE("Module '%s' failed to load, quitting", (*module)->name);
      }
    }
  }
}
