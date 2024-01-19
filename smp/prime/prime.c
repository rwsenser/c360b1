//
// from: https://www.codesdope.com/blog/article/prime-numbers-using-sieve-algorithm-in-c/
//
// mugged by RWS 2024-01-04
// #include <stdio.h>
#include "nanoprintf.h"
#include "rwsstdio.h"

int main()
{
    static int primes[100+1];
    int number,i,j;
    // printf("Enter the number\n");
    // scanf("%d",&number);
    number = 100;
    printf("n is %d", number);

    //  RWS what???
    // int primes[number+1];

    //populating array with naturals numbers
    for(i = 2; i<=number; i++)
        primes[i] = i;

    i = 2;
    while ((i*i) <= number)
    {
        if (primes[i] != 0)
        {
            for(j=2; j<number; j++)
            {
                if (primes[i]*j > number)
                    break;
                else
                    // Instead of deleteing , making elemnets 0
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }

    for(i = 2; i<=number; i++)
    {
        //If number is not 0 then it is prime
        if (primes[i]!=0)
            printf("%d",primes[i]);
    }

    return 0;
}
