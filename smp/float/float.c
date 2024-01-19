//
// float.c:  simple float test
//
// #include <stdio.h>
// #include <string.h>

#include "rwsitoa.h"
#include "rwsputs.h"

int main() {
  float c, f;
  int i1, i2;
  char buffer[120];
  c = 1.0; // 100.0;
  f = ((c * 9.0) / 5.0) + 32.0;
  // printf("%f\n",f);
  i1 = (int)f;
  i2 = (int)  ((f - i1) * 10000);
  itoa(i1, buffer, 10);
  puts(buffer);
  itoa(i2, buffer, 10);
  puts(buffer);
  // printf("%d.%d\n", i1, i2);
}
