#include <stdio.h>
#include <stdlib.h>
#include "BenjisFunctions.h"

int main()
{
    printHeader("Factorial");
    /*Find the factorial of a user-typed integer,
    and print it out on the screen*/
    int n = -1;

    printf("Enter an integer: ");
    scanf("%d",&n);
    // show error if the user enters a negative integer
    while (n < 0)
    {
        printf("Error! Please enter a positive whole number.\n");
        printf("Enter an integer: ");
        scanf("%d",&n);
    }

    printf("Factorial of %d = %llu", n, factorial(n));

    printHeader("Pointers");
    /*Test pointers*/
    int x = 3, y = 5;
    int *ip;
    ip = &y;
    printf("ip = %p - after pointing it to y\n", ip);
    x = ip;
    y = *ip+1;
    *ip = 8;
    printf("x = %d, y = %d, ip = %p", x, y, ip);

    printHeader("Prime test");
    printf("isPrime(7): %s\n", isPrime(7));
    printf("isPrime(6): %s\n", isPrime(6));

    printHeader("Testing Array Length function:");
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i;
    printf("array = ");
    for (i=0;i<NELEMS(array);i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("The number of elements in array (NELEMS(array)) = %d\n", NELEMS(array));

    return 0;
}
