//
// from: https://elixir.bootlin.com/linux/latest/source/arch/m68k/lib/memcpy.c
//

#include "rwsstddef.h"
#ifndef _MEMCPY_H_
#define _MEMCPY_H_
void *memcpy(void *to, const void *from, size_t n)
{
        void *xto = to;
        char *cto = to;
        const char *cfrom = from;
        for (; n; n--)
                *cto++ = *cfrom++;
        return xto;
}
#endif
