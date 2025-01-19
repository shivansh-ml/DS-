#include <stdio.h>
#include <stdlib.h>

int *a;

void deq();
void enq();
void peek();
int isEmpty();
int isFULL();

int front = -1, rear = -1;

int main()
{
    int i = 0;
    int ch;
    while (i == 0)
    {
        printf("\t\tQueue operation\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Exit\n");
        printf("5.Queue creation\n ");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Implementing the enqueue operation\n");
            enq();
            break;
        case 2:
            printf("Implementing the dequeue operation\n");
            deq();
            break;
        case 3:
            printf("Implementing the peek operation\n");
            peek();
            break;
        case 4:
            printf("Exiting the program");
        default:
            break;
        }
    }
}

void deq()
{
}
void enq()
{
}
void peek()
{
}
int isEmpty()
{
}
int isFULL()
{
}