#include "core_inner.hpp"
#include "config.hpp"
#include <map>
#include <string>

std::map<std::string, std::string> ox_arg_parse(int argc, char** argv)
{
  std::map<std::string, std::string> result;

  for (int i = 0; i < argc; i++) {
    char* c = argv[i];
    std::string lhs;
    std::string rhs;
    bool is_lhs = true;

    for (; *c; c++) {
      if (is_lhs) {
        if (*c == '=') {
          is_lhs = false;
          continue;
        } else {
          lhs += *c;
        }
      } else {
        rhs += *c;
      }
    }

    result[lhs] = rhs;
  }

  return result;
}

void ox_arg_apply(std::map<std::string, std::string>& args) {
  for (auto it = args.begin(); it != args.end(); it++) {
    std::string name = it->first;
    if (name.find(".") == std::string::npos) {
      name = "core." + name;
    }

    std::string module = name.substr(0, name.find("."));
    std::string param = name.substr(name.find(".") + 1);

    ox_config_set(module, param, it->second);
  }
}
