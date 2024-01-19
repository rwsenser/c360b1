//
// from: https://en.wikibooks.org/wiki/C_Programming/string.h/strcpy
//
#ifndef _STRCPY_H_
#define _STRCPY_H_
char *strcpy(char *dest, const char *src)
{
   char *save = dest;
   while(*dest++ = *src++);
   return save;
}
#endif
