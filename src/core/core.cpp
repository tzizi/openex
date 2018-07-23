#include "core.hpp"
#include "core_inner.hpp"

struct ox_module ox_core =
  {
   .name = "core",

   .init = NULL,
   .config =
   {
    .params =
    (ox_config_param[]){
     {
      .name = "verbosity",
      .nicks = (const char*[]){"v", NULL},

      .type = "int",

#if defined(OX_BUILD_RELEASE)
      .value = "1",
#else
      .value = "3",
#endif
      .help = "Verbosity of the log output",

      .variable = (void**)&ox_core_globals.verbosity
     },
     OX_CONFIG_PARAM_END},

    .on_change = NULL
   }
  };
