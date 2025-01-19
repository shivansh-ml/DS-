#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Calculator\n");
    int i=0;
    while(i==0)
    {
        printf("\tEnter your choice\n");
        printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Divison\n5.Exit\n");
        int a,b;
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Performing Addition Operation\n");
            printf("Enter two numbers\n");
            scanf("%d",&a);
            scanf("%d",&b);
            printf("Addition is %d\n",a+b);
            break;
        case 2:
            printf("Performing Subtraction Operation\n");
            printf("Enter two numbers\n");
            scanf("%d",&a);
            scanf("%d",&b);
            printf("Subtraction is %d\n",a-b);
            break;
        case 3:
            printf("Performing Multiplication Operation\n");
            printf("Enter two numbers\n");
            scanf("%d",&a);
            scanf("%d",&b);
            printf("Multiplication is %d\n",a*b);
            break;
        case 4:
            printf("Performing Divison Operation\n");
            printf("Enter two numbers\n");
            scanf("%d",&a);
            scanf("%d",&b);
            printf("Divison is %d\n",a/b);
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