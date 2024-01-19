//
// rws puts test
//
#include "rwsputs.h"

#if 0
int puts(const char* str) {
  char* p;
  p = str;  
  asm(" L     15,=A(@@PUTS)");
  asm(" BALR  14,15");
  return 121;
}
#endif
int main() {
   puts("FRED");
   return 4;
}
