#ifndef __OX_CORE_LOG_HPP__
#define __OX_CORE_LOG_HPP__


#define OX_LOG_COLOR_BLACK 0
#define OX_LOG_COLOR_RED 1
#define OX_LOG_COLOR_GREEN 2
#define OX_LOG_COLOR_YELLOW 3
#define OX_LOG_COLOR_BLUE 4
#define OX_LOG_COLOR_MAGENTA 5
#define OX_LOG_COLOR_CYAN 6
#define OX_LOG_COLOR_WHITE 7

#define OX_LOG_LEVEL_ERROR 0
#define OX_LOG_LEVEL_WARNING 1
#define OX_LOG_LEVEL_INFO 2
#define OX_LOG_LEVEL_VERBOSE 3
#define OX_LOG_LEVEL_DEBUG 4


#define OX_LOGE(...) ox_log(OX_LOG_MODULE, OX_LOG_MODULE_COLOR, OX_LOG_LEVEL_ERROR, __VA_ARGS__)
#define OX_LOGW(...) ox_log(OX_LOG_MODULE, OX_LOG_MODULE_COLOR, OX_LOG_LEVEL_WARNING, __VA_ARGS__)
#define OX_LOGI(...) ox_log(OX_LOG_MODULE, OX_LOG_MODULE_COLOR, OX_LOG_LEVEL_INFO, __VA_ARGS__)
#define OX_LOGV(...) ox_log(OX_LOG_MODULE, OX_LOG_MODULE_COLOR, OX_LOG_LEVEL_VERBOSE, __VA_ARGS__)
#define OX_LOGD(...) ox_log(OX_LOG_MODULE, OX_LOG_MODULE_COLOR, OX_LOG_LEVEL_DEBUG, __VA_ARGS__)


void ox_log(const char* module, int color, int level, const char* format, ...);


#endif
