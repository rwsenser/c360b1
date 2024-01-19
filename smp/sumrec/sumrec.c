//
// sumrec.c:   compute sum of numbers 1 to n very recursively
//
// tests that RT stack can be at least 25 deep!
//
// #include <stdio.h> 
// #include <string.h>

#include "rwsitoa.h"
#include "rwsputs.h"

#define NUM 25

int sum(int n) {
	if (n == 1) return 1;
	return (sum(n - 1) + n);
}
int main () {
	int s;
	int n;
	char buffer[120];
	puts("Sum is:");
	n = NUM;
	s = sum(n);
	itoa(s,buffer,10);
	puts(buffer);
}
