#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear;
int count = 0;

void enq();
int deq();
int peek();
int isEmpty();
int isFULL();
int traversal();

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
        printf("4.Isempty\n");
        printf("5.IsFULL\n");
        printf("6.Traversal\n");
        printf("7.Exit\n");
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
            printf("Implementing the isEmpty operation\n");
            isEmpty();
            break;
        case 5:
            printf("Implementing the isFULL operation\n");
            isFULL();
            break;
        case 6:
            printf("Implementing the traversal operation\n");
            traversal();
            break;
        case 7:
            printf("Exiting the program");
            i=7;
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

int deq()
{
    if (isEmpty() == 1)
    {
        printf("Operation cannot be performed");
        return -1;
    }
    else
    {
        struct Node *temp;
        temp = front;
        front = front->next;
        count--;
        free(temp);
        if (front == NULL)
        {
            rear = NULL;
        }
    }
}
void enq()
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (isFULL() == 0)
    {
        printf("Memory error\n");
    }
    printf("Enter the %dth element of queue\n", count);
    scanf("%d", &p->data);
    p->next = NULL;
    if (front == NULL)
    {
        front = p;
        rear = p;
    }
    else
    {
        rear->next = p;
        rear = p;
    }
    count++;
}
int peek()
{
    printf("The front element is %d", front->data);
}
int isEmpty()
{
    if (front == NULL)
    {
        printf("List is empty\n");
        return 1;
    }
    else
    {
        printf("List is not empty\n");
        return 0;
    }
}
int isFULL()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr != NULL)
    {
        printf("Queue is not full\n");
        return 1;
    }
    else
    {
        printf("Queue is full\n");
        return 0;
    }
    free(ptr);
}
int traversal()
{
    struct Node *ptr;
    ptr = front;
    while (ptr != NULL)
    {
        printf("The data is:%d\n", ptr->data);
        ptr = ptr->next;
    }
}