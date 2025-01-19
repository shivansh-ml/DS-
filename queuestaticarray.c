#include <stdio.h>
#include <stdlib.h>

#define N 3
int a[N];

void deq();
void enq();
void peek();
int isEmpty();
int isFULL();

int front = -1, rear = -1;

int main()
{
    int ch;
    while (1)
    {
        printf("\t\tQueue operation\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n ");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
            printf("Implementing the IsEmpty operation\n");
            if (isEmpty())
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 5:
            printf("Implementing the IsFull operation\n");
            if (isFULL())
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
            break;
        case 6:
            printf("Exiting the program\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

void deq()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dequeued element is %d\n", a[front]);
        front++;
        // Reset front and rear if queue becomes empty
        if (front > rear) 
        {
            front = rear = -1; 
        }
    }
}

void enq()
{
    if (isFULL())
    {
        printf("Queue is already full\n");
    }
    else
    {
        if (front == -1) // If the queue is empty
        {
            front = 0;
        }
        rear++;
        printf("Enter the element to be inserted: ");
        scanf("%d", &a[rear]);  // Insert the element at the rear
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The front element is %d\n", a[front]);
    }
}

int isEmpty()
{
    return (front == -1);  // Queue is empty when front is -1
}

int isFULL()
{
    return (rear == N - 1);  // Queue is full when rear is at the last index
}
