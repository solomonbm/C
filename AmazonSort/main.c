#include <stdio.h>
#include <stdlib.h>
#define NELEMS(x) sizeof(x)/sizeof(x[0])
void printResult(int arr1[], int arr2[], int arr3[])
{
    int x, y, z;
    int i, j, k;
    x = arr1[0];
    for(i=0;i<NELEMS(arr1);i++)
    {
        x = arr1[i];
        printf("x = %d, i = %d, NELEMS(arr1) = %d, sizeof(arr1) = %d\n",x,i,NELEMS(arr1),sizeof(arr1));
    }
    //printf("(%d,%d,%d)\n",x,y,z);
}
int main()
{
    printf("Hello world!\n");
    int arr1[] = {0,1};
    int arr2[] = {2,3,4};
    int arr3[] = {4,5,7};
    printResult(arr1,arr2,arr3);
    return 0;
}
