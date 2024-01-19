//
//  ivp3.c:  Verify that puts() and itoa() are working
//

#include "rwsputs.h"
#include "rwsitoa.h"
// 120 is max of actual display line with c360

char buffer1[120];
char buffer2[120];
int a = 1;
int b = 2;
int c; 
int errs = 0;
int main() {
	//
	puts("sum 1 + 2:");
    c = a + b;
	itoa(c,buffer1,10);
	puts(buffer1);
	if (c != 3) {errs++; puts("error: wrong result");}
	//
	c = 1234;
	puts("should display '1234'");
	itoa(c,buffer1,10);
	int i;
	for (i=0; i < 4; i++) {
	  if (buffer1[i] != '0' + (i+1)) {errs++; puts("error: bad itoa() result (..)");}
	}
	if (buffer1[4] != '\0') {errs++; puts("error: bad itoa() result (;;)");}
	puts(buffer1);   
	//
	itoa(errs,buffer2,10);
	puts("number of errors:");
	puts(buffer2);
    return errs;
}
