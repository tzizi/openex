#include "globals.hpp"
#include "core_inner.hpp"

#include "core.hpp"

ox_core_globals_t ox_core_globals;

extern ox_module** ox_modules;

void ox_core_globals_init() {
  ox_core_globals.modules = ox_modules;
}
