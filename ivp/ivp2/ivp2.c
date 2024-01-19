//
//  ivp2.c:  Verify that basic math and puts() function are working
//
#include "rwsputs.h"

int a = 1;
int b = 2;
int c;
float fa = 1.0;
float fb = 2.0;
float fc;
int errs = 0;
int main() {
	// do int math
    c = a + b;
	if (c != 3) errs++; else puts("integer add OK");
	// do float math
	fc = fa + fb;
	if (fc != 3.0) errs++; else puts("float   add OK");
    return errs;
}
