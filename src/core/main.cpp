#include "core_inner.hpp"
#include "arg.hpp"
#include "config.hpp"
#include "modules.hpp"

int main(int argc, char** argv) {
  ox_core_globals_init();
  ox_config_init();

  auto args = ox_arg_parse(argc - 1, argv + 1);
  ox_arg_apply(args);

  ox_modules_init();
}
