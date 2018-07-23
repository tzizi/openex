#include "core_inner.hpp"
#include "config.hpp"
#include "modules.hpp"
#include <string.h>


static std::string ox_config_prefix(std::string& module, std::string& param)
{
  return module + std::string(".") + param;
}

std::string ox_config_get(std::string module, std::string param)
{
  std::string name = ox_config_prefix(module, param);

  auto it = ox_core_globals.config.find(name);
  if (it != ox_core_globals.config.end()) {
    return it->second;
  } else {
    return "";
  }
}

static ox_config_param* ox_config_get_param(std::string& module_name, std::string& param_name)
{
  ox_module* module = ox_modules_get(module_name);
  if (module) {
    if (module->config.params) {
      ox_config_param* param = module->config.params;

      for (; param->name; param++) {
        if (std::string(param->name) == param_name) {
          return param;
        }

        if (param->nicks) {
          const char** nick = param->nicks;
          for (; *nick; nick++) {
            if (!strcmp(*nick, param_name.c_str()))
              return param;
          }
        }
      }
    }
  }

  return NULL;
}

static void ox_config_update(std::string& module_name, std::string& param_name, std::string& value)
{
  ox_module* module = ox_modules_get(module_name);
  if (module) {
    if (module->config.on_change) {
      module->config.on_change(param_name, value);
    }

    if (module->config.params) {
      ox_config_param* param = module->config.params;

      for (; param->name; param++) {
        if (std::string(param->name) == param_name) {
          if (!param->variable)
            break;

          if (!strcmp(param->type, "int")) {
            *((int*)param->variable) = atoi(value.c_str());
          } else if (!strcmp(param->type, "string")) {
            *((std::string*)param->variable) = value;
          }

          break;
        }
      }
    }
  }
}

void ox_config_set(std::string module_name, std::string param_name, std::string value)
{
  std::string name = ox_config_prefix(module_name, param_name);

  ox_config_param* param = ox_config_get_param(module_name, param_name);
  if (param)
    param_name = param->name;

  OX_LOGV("Setting %s.%s = %s", module_name.c_str(), param_name.c_str(), value.c_str());
  ox_core_globals.config[name] = value;

  ox_config_update(module_name, param_name, value);
}

void ox_config_init()
{
  struct ox_module** module = ox_core_globals.modules;

  for (;*module; module++) {
    ox_config_param* param = (*module)->config.params;

    if (param) {
      for (; param->name; param++) {
        if (param->value) {
          ox_config_set((*module)->name, param->name, param->value);
        }
      }
    }
  }
}
