//
// from: https://en.wikibooks.org/wiki/C_Programming/string.h/strcmp
//
#ifndef _STRCMP_H_
#define _STRCMP_H_
int strcmp (const char * s1, const char * s2)
{
    for(; *s1 == *s2; ++s1, ++s2)
        if(*s1 == 0)
            return 0;
    return *(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1;
}
#endif
