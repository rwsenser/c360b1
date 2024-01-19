//
// mem.c:   test simple mem functions
//
#include "rwsmemcpy.h"
#include "rwsmemcmp.h"
#include "rwsputs.h"
#include "rwsitoa.h"

int main () {
	char data[4] = "abcd";
    char data2[120];
    char buffer[120];
	int n;
    int b;
    int err = 0; 
    int ret = 0;
    // test memcpy
    memcpy(data2,data,sizeof(data));
    if (data2[0] != 'a' ||
        data2[1] != 'b' ||
        data2[2] != 'c' ||
        data2[3] != 'd') { puts("memcpy failed (1)"); err++;}
    //test memcmp
    if (memcmp(data,data2,sizeof(data)) != 0) { puts("memcmp failed (1)"); err++;}
    if (memcmp("aa","ab",2) != -1) { puts("memcmp failed (2)"); err++;}
    if (memcmp("xxxz", "xxx   ",4) != 1) { puts("memcmp failed (3)"); err++;}	
    // test memcpy
    memcpy(data2,&data2[3],1); 
    if (data2[0] != 'd' ||
        data2[1] != 'b' ||
        data2[2] != 'c' ||
        data2[3] != 'd') { puts("memcpy failed (2)"); err++;}
    // more test memcmp
    b = memcmp(data,&data[2],sizeof(data));
    if (b != -1) { puts("memcmp failed (-1)"); err++;} 
    b = memcmp(&data[2],data,sizeof(data));
    if (b != 1) { puts("memcmp failed (+1)"); err++;}  
    b = memcmp("1234567890", "1234567890",10);
    if (b != 0) { puts("memcmp failed (0)"); err++;}       
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
