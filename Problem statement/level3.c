#include <stdio.h>
#include <stdlib.h>

int a, b;

void addition()
{
    printf("Performing Addition Operation\n");
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Addition is %d\n", a + b);
}

void subtraction()
{
    printf("Performing Subtraction Operation\n");
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Subtraction is %d\n", a - b);
}

void multiplication()
{
    printf("Performing Multiplication Operation\n");
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Multiplication is %d\n", a * b);
}

void divison()
{
    printf("Performing Divison Operation\n");
    printf("Enter two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Division is %d\n", a / b);
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
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            divison();
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