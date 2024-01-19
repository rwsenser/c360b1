// #include "stdio.h"

#include "rwsputs.h"
#include "rwsitoa.h"

#undef FULL
#define FULL
int a = 1;
int b = 2;
int c;
int main() {
#ifdef FULL	
    char buffer[120];
	
	itoa(a,buffer,10);
	puts("a is ");
	puts(buffer);
	
	itoa(b,buffer,10);
	puts("b is ");
	puts(buffer);
	
	puts("a + b is");
#endif	
    c = a + b;
#ifdef FULL	
	itoa(c,buffer,10);
	puts(buffer);
#endif	
    return c;
}
