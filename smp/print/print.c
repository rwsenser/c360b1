// 
// print.c: test nanoprintf
//
#include "rwsputs.h"
#include "nanoprintf.h"
#include "rwsstdio.h"
#if 0
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

int main() {

	char buffer[120];
	int d = 1234;
    puts("TEST PRINT");
    printf("Say 'Hi Dick'");
	npf_snprintf(buffer, sizeof(buffer), "npf_snprintf here $$%6d$$", d);
	puts(buffer);
	
    return 0;
}
