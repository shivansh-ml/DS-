#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL, *temp;

int insert_beg();
int listcreation();
int insertion_end();
int display();
int insert_after();
int insert_before();

int main()
{
    int i = 0, ch;
    while (i == 0)
    {
        printf("\tLinked List Operation \t\n");
        printf("Enter 1 for linked list creation\n");
        printf("Enter 2 for  insertion at beginning\n");
        printf("Enter 3 for insertion at end\n");
        printf("Enter 4 for insertion after a number\n");
        printf("Enter 5 for insertion before a number\n");
        printf("Enter 6 for display\n");
        printf("Enter 7 for exiting the program\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            listcreation();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insertion_end();
            break;
        case 4:
            insert_after();
            break;
        case 5:
            insert_before();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("\n\nDo you wish to continue?\n");
        printf("Press 0 to continue: ");
        scanf("%d", &i);
    }
}
int listcreation()
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
        printf("List already exists\n");
    }
}
int insertion_end()
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("\n List is empty\n");
    }
    else
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("\n Enter the data :");
        scanf("%d", &ptr->data);
        temp->next = ptr;
        ptr->next = NULL;
        temp = ptr;
    }
}
int insert_beg()
{
    struct Node *ptr;
    if (head == NULL)
        printf("List already exists\n");
    else
    {
        ptr = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data\n");
        scanf("%d", &ptr->data);
        ptr->next = head;
        head = ptr;
    }
}
int display()
{
    struct Node *p;
    if (head == NULL)
    {
        printf("\n List is empty\n");
    }
    else
    {
        p = head;
        printf("The data is ");
        while (p != NULL)
        {
            printf("->%d ", p->data);
            p = p->next;
        }
    }
}
int insert_after()
{
    struct Node *ptr, *tem;
    int a, count = 0;
    if (head == NULL)
    {
        printf("\n List is empty\n");
    }
    else
    {
        printf("Enter the number you want to  insert after\n");
        scanf("%d", &a);
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == a)
            {
                tem = (struct Node *)malloc(sizeof(struct Node));
                printf("Enter the data\n");
                scanf("%d", &tem->data);
                tem->next = ptr->next;
                ptr->next = tem;
                count++;
            }
            ptr = ptr->next;
        }
        if (count == 0)
        {
            printf("Number you searched for is not in the list\n");
        }
    }
}
int insert_before()
{
    struct Node *ptr, *tem, *prev;
    int a, count = 0;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("Enter the number you want to insert before\n");
        scanf("%d", &a);
        ptr = head;
        prev = NULL;
        while (ptr != NULL)
        {
            if (ptr->data == a)
            {
                tem = (struct Node *)malloc(sizeof(struct Node));
                printf("Enter the data: ");
                scanf("%d", &tem->data);
                if (prev == NULL)
                {
                    tem->next = head;
                    head = tem;
                }
                else
                {
                    tem->next = ptr;
                    prev->next = tem;
                }
                count++;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if (count == 0)
        {
            printf("Number you searched for is not in the list\n");
        }
    }
}