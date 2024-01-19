// tstsamp1.c - some simple C code with a struct
// memcpy reduced from: https://elixir.bootlin.com/linux/latest/source/arch/m68k/lib/memcpy.c
// #include "stdio.h"
// fix compiler warning...
#define size_t unsigned int
struct acb {
  char   type;
  char   res;
  char   cmd[2];
  char   cid[4];
  short  fnr;
  short  rsp;
  /* and so on */
} myACB;
void *memcpy(void *to, const void *from, size_t n)
{
        void *xto = to;
        char *cto = to;
        const char *cfrom = from;
        for (; n; n--)
                *cto++ = *cfrom++;
        return xto;
}
int main() {
   char cmd[3] = "L1";
   int s;
   s = 2;
   myACB.type = 0x40;
   myACB.res = 0x00;
   memcpy((void *) myACB.cmd,(void *) cmd,s); // avoid using constants
   myACB.fnr = 7;
   myACB.rsp = 0;
   return 0;
}
