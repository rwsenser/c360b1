// libs.c  Test runtime libs
//
// rws #include <stdio.h>
#include "rwsputs.h"
#include "rwsitoa.h"
#include "rwsatoi.h"
#include "rwsstrlen.h"

int main(void) {
	int len;
    int len2;
    int errs = 0;
	char buffer[120];
	len = strlen("FRED");
	itoa(len,buffer,10);
	puts("FRED RESULTS:");
    if (len != 4) errs++;
	puts(buffer);
    len2 = atoi(buffer);
    if (len != len2) errs++;
    if (errs > 0) {
        puts("error(s) found with itoa()/atoi()");
    } else {
        puts("no errors found");
    }        
    return errs;
}
