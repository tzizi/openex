#ifndef __OX_CORE_ARG_HPP__
#define __OX_CORE_ARG_HPP__


#include <map>
#include <string>

std::map<std::string, std::string> ox_arg_parse(int argc, char** argv);
void ox_arg_apply(std::map<std::string, std::string>& args);


#endif
