//
// from: https://en.wikibooks.org/wiki/C_Programming/string.h/strcat
//
#ifndef _STRCAT_H_
#define _STRCAT_H_
// #define size_t int
char * strcat(char *dest, const char *src)
{
    size_t i,j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}
// #undef size_t
#endif
