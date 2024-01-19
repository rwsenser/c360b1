// RWSITOA.h
//
// from: https://en.wikibooks.org/wiki/C_Programming/stdlib.h/itoa
// and
// from: https://en.wikibooks.org/wiki/C_Programming/string.h/strlen
//

#include "rwsstrlen.h"

#ifndef _ITOA_H_
#define _ITOA_H_
 void __reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
 /* itoa:  convert n to characters in s */
 void itoa(int n, char s[], int base)  // base is ignored, sorry!
 {
     int i, sign;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     __reverse(s);
 }
#endif
// end of rwsitoa.cpy
