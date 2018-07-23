#ifndef __OX_CONFIG_HPP__
#define __OX_CONFIG_HPP__


#include <string>


struct ox_config_param
{
  const char* name;
  const char** nicks;

  const char* type;

  const char* value;
  const char* help;

  void** variable;
};

#define OX_CONFIG_PARAM_END (ox_config_param)                   \
    {                                                           \
     .name = NULL,                                              \
     .nicks = NULL,                                             \
     .type = NULL,                                              \
     .value = NULL,                                             \
     .help = NULL,                                              \
     .variable = NULL                                           \
    }

struct ox_config_module
{
  struct ox_config_param* params;

  bool (*on_change)(std::string& param, std::string& value);
};

std::string ox_config_get(std::string module, std::string param);
void ox_config_set(std::string module, std::string param, std::string value);

void ox_config_init();


#endif
