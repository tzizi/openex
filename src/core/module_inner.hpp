#ifndef __OX_MODULE_INNER_HPP__
#define __OX_MODULE_INNER_HPP__


#define OX_LOG_MODULE OX_MODULE_NAME
#define OX_LOG_MODULE_COLOR OX_MODULE_COLOR
#include "log.hpp"

#define OX_CONFIG_GET(param) ox_config_get(OX_MODULE_NAME, param)
#define OX_CONFIG_SET(param, value) ox_config_set(OX_MODULE_NAME, param, value)
#include "config.hpp"


#endif
