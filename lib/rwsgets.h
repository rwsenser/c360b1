//
// Q&D hack providing a C wrapper for assembler @@GETS, located in the C run-time
//
// int puts(const char* str) {  with this C compiler const is ignored here...
#ifndef _GETS_H_
#define _GETS_H_
#include "rwsstddef.h"
#include "rwsstrlen.h"
/* DO NOT CHANGE THIS CODE WITH ADJUSTING @@GETS!! */
int gets(char* str) {
    int len;
    char* p;
    p = str; 
    // asm code accesses str in arg list -- don't change this code
    // without checking that the offset in the asm code did not change!
    asm(" L     15,=A(@@GETS)");
    asm(" BALR  14,15");
    len = strlen(p);
    return len;     // len of zero means eof
}
#endif

