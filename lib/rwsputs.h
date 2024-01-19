//
// Q&D hack providing a C wrapper for assembler @@PUTS, located in the C run-time
//
// int puts(const char* str) {  with this C compiler const is ignored here...
#ifndef _PUTS_H_
#define _PUTS_H_
int puts(char* str) {
  char* p;
  p = str; 
  // behind the screens R1 contains the string address
  // and @@PUTS expects the string address in R1!!  
  asm(" L     15,=A(@@PUTS)");
  asm(" BALR  14,15");
  return 121;
}
#endif
