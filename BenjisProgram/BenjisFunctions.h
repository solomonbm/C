#include <stdio.h>
#include <stdbool.h>
#define NELEMS(x) sizeof(x)/sizeof(x[0])

void printHeader(char header[])
{
    printf("\n");
    printf("%s:\n", header);
}
unsigned long long factorial(int n)
{
    int i;
    unsigned long long factorial = 1;
    for(i=1; i<=n; i++)
    {
        factorial *= i; // factorial = factorial*i;
    }

    return factorial;
}

const char *isPrime(int n)
{
    const char *x = ((factorial(n-1) + 1)%n == 0) ? "true" : "false";
    return x;
}

