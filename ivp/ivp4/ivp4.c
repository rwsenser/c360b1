//
//  ivp4:  Verify that puts(), itoa() and strxxx() functions are working
//
#include "rwsputs.h"
#include "rwsitoa.h"
#include "rwsstrcat.h"
#include "rwsstrcmp.h"
#include "rwsstrcpy.h"
#include "rwsstrlen.h"
// 120 is max of actual display line with c360
char word1[4] = "aim";
char word2[16] = "high";
char buffer1[120];
char buffer2[120];
int l;
int errs = 0;
int main() {
	//
	puts("ivp4 results:");
	//
	strcpy(buffer1,"aim: ");
	strcat(buffer1,word1);
	puts(buffer1);
	//
	strcpy(buffer1,"high: ");
	strcat(buffer1,word2);
	puts(buffer1);
	//
	strcpy(buffer2,word1);
	l = strlen(buffer2);
	if (l != ((sizeof(word1) - 1))) {errs++; puts("error: len should be 3"); } else {puts("strlen() result OK");}
	// insert space by brute force
	puts("insert ' '");
	buffer2[l] = ' ';
	buffer2[l+1] = '\0';
	//
	strcat(buffer2,word2);
	puts("buffer2 concat result is:");
	puts(buffer2);	
	//
	if (strcmp(buffer2,"aim high") != 0) {
		errs++; puts("error: bad strcmp results");
    } else {
		puts("strcmp() result OK");
	}
	// show error count
	itoa(errs,buffer2,10);
	puts("number of errors:");
	puts(buffer2);
    return errs;
}
