#include <stdio.h>
#include <stdlib.h>

int addition(int a, int b)
{
    printf("Performing Addition Operation\n");
    return a + b;
}

int subtraction(int a, int b)
{
    printf("Performing Subtraction Operation\n");
    return a - b;
}

int multiplication(int a, int b)
{
    printf("Performing Multiplication Operation\n");
    return a * b;
}

int divison(int a, int b)
{
    printf("Performing Divison Operation\n");
    return a / b;
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
            c=addition(a,b);
            printf("Addition is %d\n",c);
            break;
        case 2:
            c=subtraction(a,b);
            printf("Subtraction is %d\n",c);
            break;
        case 3:
            c=multiplication(a,b);
            printf("Multiplication is %d\n",c);
            break;
        case 4:
            c=divison(a,b);
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