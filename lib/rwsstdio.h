// rwsstdio.n
// << basically a "fake" stdio. >>
//
// This is a stand-in printf() function
//

#include "rwsstddef.h"
#include "rwsstdarg.h"
#include "rwsputs.h"

// depends upon npf_vsnprintf() !!

#ifndef _STDIO_H_
#define _STDIO_H_
int printf(const char *format, ...) {
  char buffer[120];
  va_list val;
  va_start(val, format);
  int const rv = npf_vsnprintf(buffer, sizeof(buffer), format, val);
  va_end(val);
  puts(buffer);
  return rv;
}
#endif
