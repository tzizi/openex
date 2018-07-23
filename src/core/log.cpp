#include "core_inner.hpp"
#include "log.hpp"
#include <stdio.h>
#include <stdarg.h>

void ox_log(const char* module, int color, int level, const char* format, ...)
{
  va_list list;

  if (level > ox_core_globals.verbosity)
    return;

  printf("\u001b[3%i;1m[%s]\u001b[0m ", color, module);

  if (level == OX_LOG_LEVEL_ERROR)
    printf("\u001b[31m");

  va_start(list, format);
  vprintf(format, list);
  va_end(list);

  if (level == OX_LOG_LEVEL_ERROR)
    printf("\u001b[30m");

  puts("");
}
