//
// sample c/360 app
//
// SEE LICENSE AT END OF FILE
//
// input data from SYSIN with 10 char name and 3 char age
// output cnt of records, high, low, and int avg age
//
#undef PC
// define PC
#if PC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#else
// #include "rwsstddef.h"
// #include "rwsstdarg.h"
#include "rwsatoi.h"
#include "rwsmemcpy.h"
#include "rwsgets.h"
// #include "rwsputs.h"

#include "rwsstdio.h"
#include "nanoprintf.h"
#endif
int main () {
    int age;
    int sum = 0;
    int cnt = 0;
    int hi = -1;
    int lo = 99999;
    char name[11];
    char agebuff[4];
    struct data {
        char name[10];
        char age[3];
    };
    char buffer[81];
    struct data* record_ptr;
    while (1) {
#ifdef PC
        puts(":");
#endif        
        if (gets(buffer) < 1) break;
        record_ptr = (struct data*) buffer;
        cnt++;
        // convert age as char to int
        memcpy(agebuff, record_ptr->age, sizeof(record_ptr->age));
        agebuff[3] = '\0';
        age = atoi(agebuff);
        // copy name and make a C-string
        memcpy(name, record_ptr->name, sizeof(name));
        name[10] = '\0';
        // compute stats
        sum += age;
        if (age > hi) hi = age;
        if (age < lo) lo = age;
        
        printf("%s %d\n", name, age);
    }
    printf(" cnt: %d\n", cnt);
    if (cnt > 0) {    
        printf("high: %d\n", hi);
        printf("  lo: %d\n", lo);
        printf("int avg: %d", sum / cnt);
    }    
}
/*
MIT License

Copyright (c) 2024 rwsenser

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE
*/
