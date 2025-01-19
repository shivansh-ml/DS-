#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL, *temp;

int insertion();
int insertion_Beg();
int deletion();
int deletion_Beg();
int Searching();
int Sorting();
int Traversal();
int Reversal();

int main()
{

    int c, i = 0;
    while (i != 1)
    {
        printf("\n 1- Insertion Operation");
        printf("\n 2- Deletion Operation");
        printf("\n 3- Searchin Operation");
        printf("\n 4- Sorting Operation");
        printf("\n 5- Traversal Operation\n : ");
        scanf(" %d", &c);
        switch (c)
        {
        case 1:
            printf("\n In am in Insertions Operation");
            insertion_Beg();
            break;
        case 2:
            printf("\n In am in Deletion Operation");
            deletion_Beg();
            break;
        case 3:
            printf("\n In am in Search Operation");
            break;
        case 4:
            printf("\n In am in Sorting Operation");
            break;
        case 5:
            printf("\n In am in Traversal Operation");
            Traversal();
            break;
        case 6:
            printf("\n In am in Reversal Operation");
            Reversal();
            break;
        default:
            printf("\n Wrong Choice");
        }
        printf("\n\nDo u want to cont...");
        scanf("%d", &i);
        printf("\n\n");
    }
}
int insertion()
{
    struct Node *ptr;
    if (head == NULL)
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("\n Enter the data :");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        temp = ptr;
        head = ptr;
    }
    else
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("\n Enter the data :");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        temp->next = ptr;
        temp = ptr;
    }
}
int deletion()
{
    struct Node *p, *t;
    p = head;
    while (((p->next)->next) != NULL)
    {
        p = p->next;
    }
    t = p->next;
    p->next = NULL;
}
int insertion_Beg()
{
    struct Node *ptr, *t;
    if (head == NULL)
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("\n Enter the data :");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        temp = ptr;
        head = ptr;
    }
    else
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("\n Enter the data :");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        temp = head;
        ptr->next = temp;
        head = ptr;
    }
}
int deletion_Beg()
{
    temp = head;
    head = head->next;
    free(temp);
}
int Searching()
{
}
int Sorting()
{
}
int Traversal()
{
    struct Node *p;
    p = head;
    while (p != NULL)
    {
        printf("\n The data is : %d ", p->data);
        p = p->next;
    }
}
int Reversal()
{
}