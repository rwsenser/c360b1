//
// rws gets() test
//
#include "rwsitoa.h"
#include "rwsgets.h"
#include "rwsputs.h"

int main() {
   int len;
   char buffer[121];
   char buffer2[121];
   puts("GETS #1");
   len = gets(buffer);
   itoa(len,buffer2,10);
   puts("LENGTH:");
   puts(buffer2);
   puts("ECHO:");
   puts(buffer);
   puts("GETS #2");
   len = gets(buffer);
   itoa(len,buffer2,10);
   puts("LENGTH:");
   puts(buffer2);
   puts("ECHO:");
   puts(buffer);  
   puts("GETS #3");
   len = gets(buffer);
   itoa(len,buffer2,10);
   puts("LENGTH:");
   puts(buffer2);
   puts("ECHO:");
   puts(buffer);  
   return 0;
}
