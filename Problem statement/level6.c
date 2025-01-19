#include <stdio.h>
#include <stdlib.h>

int addition(int *a, int *b, int *c)
{
    printf("Performing Addition Operation\n");
    *c= *a + *b;
}

int subtraction(int *a, int *b,int *c)
{
    printf("Performing Subtraction Operation\n");
    *c= *a - *b;
}

int multiplication(int *a, int *b,int *c)
{
    printf("Performing Multiplication Operation\n");
    *c= *a * *b;
}

int divison(int *a, int *b,int *c)
{
    printf("Performing Divison Operation\n");
    *c= *a / *b;
}

int main()
{
    printf("Calculator\n");
    int i = 0;
    while (i == 0)
    {
        int a, b;
        printf("Enter two numbers\n");
        scanf("%d", &a);
        scanf("%d", &b);
        printf("\tEnter your choice\n");
        printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Divison\n5.Exit\n");
        int ch;
        int c;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addition(&a,&b,&c);
            printf("Addition is %d\n",c);
            break;
        case 2:
            subtraction(&a,&b,&c);
            printf("Subtraction is %d\n",c);
            break;
        case 3:
            multiplication(&a,&b,&c);
            printf("Multiplication is %d\n",c);
            break;
        case 4:
            divison(&a,&b,&c);
            printf("Divison is %d\n",c);
            break;
        case 5:
            printf("Performing Exit Operation\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("Do you wish to continue\n");
        scanf("%d", &i);
    }
}