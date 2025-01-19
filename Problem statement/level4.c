#include <stdio.h>
#include <stdlib.h>

int a, b;

int addition()
{
    printf("Performing Addition Operation\n");
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    return a + b;
}

int subtraction()
{
    printf("Performing Subtraction Operation\n");
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    return a - b;
}

int multiplication()
{
    printf("Performing Multiplication Operation\n");
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    return a * b;
}

int divison()
{
    printf("Performing Divison Operation\n");
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    return a / b;
}

int main()
{
    printf("Calculator\n");
    int i = 0;
    while (i == 0)
    {
        printf("\tEnter your choice\n");
        printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Divison\n5.Exit\n");
        int ch;
        int c;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            c=addition();
            printf("Addition is %d\n",c);
            break;
        case 2:
            c=subtraction();
            printf("Subtraction is %d\n",c);
            break;
        case 3:
            c=multiplication();
            printf("Multiplication is %d\n",c);
            break;
        case 4:
            c=divison();
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