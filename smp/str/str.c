//
// str.c:   test simple str functions
//
#include "rwsstrlen.h"
#include "rwsstrcpy.h"
#include "rwsstrcat.h"
#include "rwsstrcmp.h"
#include "rwsputs.h"
#include "rwsitoa.h"

int main () {
	char data[120] = "abcd";
    char data2[120];
    char buffer[120];
	int n;
    int b;
    int err = 0; 
    int ret = 0;
    // test strlen
    n = strlen(data);
    if (n != 4) { puts("strlen failed"); err++;}
    // test strcpy
    strcpy(data2,data);
    n = strlen(data2);
    if (n != 4) { puts("strcpy failed (1)"); err++;}
    if (data2[0] != 'a' ||
        data2[1] != 'b' ||
        data2[2] != 'c' ||
        data2[3] != 'd' ||
        data2[4] != '\0') { puts("strcpy failed (2)"); err++;}
    //test strcat 
    strcat(data2,"z");
    n = strlen(data2);
    if (n != 5) { puts("strcat failed (1)"); err++;}    
    if (data2[0] != 'a' ||
        data2[1] != 'b' ||
        data2[2] != 'c' ||
        data2[3] != 'd' ||
        data2[4] != 'z' ||
        data2[5] != '\0') { puts("strcat failed (2)"); err++;} 
    // test strcmp
    b = strcmp(data,data2);
    if (b != -1) { puts("strcmp failed (-1)"); err++;} 
    b = strcmp(data2,data);
    if (b != 1) { puts("strcmp failed (+1)"); err++;}  
    b = strcmp("1234567890", "1234567890");
    if (b != 0) { puts("strcmp failed (0)"); err++;}       
    // final results
    if (err == 0) {
        puts("no errors detected.");
    } else {
        puts("Number of error detected:");
        itoa(err,buffer,10);
        puts(buffer);
        ret = 15;
    }
    return ret;
}
