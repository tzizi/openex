#ifndef __OX_MODULE_HPP__
#define __OX_MODULE_HPP__


#include "config.hpp"

struct ox_module {
  const char* name;

  bool (*init)();
  struct ox_config_module config;
};


#endif
