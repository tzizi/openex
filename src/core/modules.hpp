#ifndef __OX_CORE_MODULES_HPP__
#define __OX_CORE_MODULES_HPP__


#include "module.hpp"

struct ox_module* ox_modules_get(std::string name);
void ox_modules_init();


#endif
