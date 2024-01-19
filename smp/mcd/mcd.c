/**
 * Máximo común divisor en C con el algoritmo de Euclides
 * implementado con ciclo while y con recursión / recursividad
 * @date 2019-12-18
 * @author parzibyte
 * @see https://parzibyte.me/blog
 * */
// muggd by rws
// #include <stdio.h>
#include "rwsputs.h"
#include "rwsitoa.h"

int maximo_comun_divisor(int a, int b) {
    int temporal;//Para no perder b
    while (b != 0) {
        temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}
// rws
#if 1
int maximor_comun_divisor(int a, int b) {
    if (b == 0) return a;
    return maximor_comun_divisor(b, a % b);
}
#endif

int main(void) {
#if 0
    printf("MCD de 50 y 120: %d\n", maximo_comun_divisor(50, 120));
    printf("MCD de 50 y 120 (recursivo): %d\n", maximo_comun_divisor_recursivo(50, 120));
    printf("MCD de 7 y 5: %d\n", maximo_comun_divisor(7, 5));
    printf("MCD de 7 y 5 (recursivo): %d\n", maximor_comun_divisor(7, 5));
#endif
	puts("mcd of 6 and 9");
    int d = maximo_comun_divisor(6, 9);
	char buffer[120];
	itoa(d, buffer, 10);
	puts(buffer);
	//
	puts("mcd recursive of 6 and 9");
    d = maximor_comun_divisor(6, 9);
	itoa(d, buffer, 10);
	puts(buffer);
    return d;
}
