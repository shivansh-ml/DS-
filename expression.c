#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *a;
    printf("Code to eavluate an expression\n");
    a=(int *)malloc(7*sizeof(int));
    printf("Enter the following values\n");
    printf("The value of A variable is: ");
    scanf("%d",&a[0]);
    printf("The value of B variable is: ");
    scanf("%d",&a[1]);
    printf("The value of D variable is: ");
    scanf("%d",&a[2]);
    printf("The value of E variable is: ");
    scanf("%d",&a[3]);
    printf("The value of F variable is: ");
    scanf("%d",&a[4]);
    printf("The value of G variable is: ");
    scanf("%d",&a[5]);
    printf("The value of I variable is: ");
    scanf("%d",&a[6]);
    int func=((a[0]+a[1])*a[2]/a[3])+a[4]^a[6]*a[5];
    printf("Function is: %d",func);
}