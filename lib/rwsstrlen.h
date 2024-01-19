//
// from: https://en.wikibooks.org/wiki/C_Programming/string.h/strlen
//
#include "rwsstddef.h"

#ifndef _STRLEN_H_
#define _STRLEN_H_
size_t strlen(const char * str)
{
    const char *s;
    for (s = str; *s; ++s) {}
    return(s - str);
}
#endif
