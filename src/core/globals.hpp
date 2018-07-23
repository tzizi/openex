#ifndef __OX_CORE_GLOBALS_HPP__
#define __OX_CORE_GLOBALS_HPP__


#include <map>
#include <string>

struct ox_module;
struct ox_core_globals_t
{
  std::map<std::string, std::string> config;
  ox_module** modules;

  int verbosity;
};

extern ox_core_globals_t ox_core_globals;

void ox_core_globals_init();


#endif
