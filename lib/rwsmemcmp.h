//
// from: https://www.javatpoint.com/memcmp-in-c
//
// seriously mugged by RWS

#ifndef _MEMCMP_H_
#define _MEMCMP_H_
int memcmp(const void *strng1, const void *strng2, int length) {  
  char *x = (char *) strng1;  
  char *y = (char *) strng2;
  unsigned char ux;
  unsigned char uy;  
  int comparisoncheck = 0;  
  //To check that pointers are pointing to same blocks.  
  if (strng1 == strng2) {  
    return comparisoncheck;  
  }  
  while (length > 0) {  
    if (*x != *y) { //Comparison between un matching charachters
      ux = (unsigned char) *x;
      uy = (unsigned char) *y;	  
      // comparisoncheck = (*x >*y)?1:-1;  
	  comparisoncheck = (ux > uy)?1:-1;  
      break;  
    }  
    length--;  
    x++;  
    y++;  
  }  
  return comparisoncheck;  
}
#endif
