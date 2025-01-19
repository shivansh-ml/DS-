#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL, *temp;
int count = 0;

int listcreation();
int display();
int del_beg();
int del_end();
int del_after();
int del_before();

int main()
{
    int i = 0, ch;
    while (i == 0)
    {
        printf("\n\n\tDoubly Linked List Menu\n");
        printf("Enter 1 for linked list creation\n");
        printf("Enter 2 for  deletion at beginning\n");
        printf("Enter 3 for deletion at end\n");
        printf("Enter 4 for deletion after a number\n");
        printf("Enter 5 for deletion before a number\n");
        printf("Enter 6 for display\n");
        printf("Enter 7 for exiting the program\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            listcreation();
            break;
        case 2:
            del_beg();
            break;
        case 3:
            del_end();
            break;
        case 4:
            del_after();
            break;
        case 5:
            del_before();
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
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node 1: ");
        scanf("%d", &head->data);
        head->next = NULL;
        head->prev = NULL;
        temp = head;
        count++;
    }
    else
    {
        struct Node *p;
        p = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", count + 1);
        scanf("%d", &p->data);
        p->prev = temp;
        temp->next = p;
        p->next = NULL;
        temp = p;
        count++;
    }
}
int display()
{
    struct Node *p;
    p = head;
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
int del_beg()
{
    if (head == NULL)
    {
        printf("\n List is empty\n");
    }
    else
    {
        struct Node *tem;
        tem = head;
        head = head->next;
        free(tem);
    }
}
int del_end()
{
    struct Node *p, *tem;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        p = head;
        while (p != NULL)
        {
            if (p->next == NULL)
            {
                temp = p;
                p = p->prev;
                free(temp);
            }
        }
    }
}
int del_before()
{
    struct Node *p, *tem;
    int pos;
    if (head == NULL)
    {
        printf("\n List is empty\n");
        return 0;
    }
    printf("\nEnter the position of the node before which you want to delete: ");
    scanf("%d", &pos);
    int count = 1;
    p = head;
    while (p != NULL)
    {
        if (count == pos - 1)
        {
            if (p->prev != NULL)
            {
                tem = p->prev;
                if (tem->prev != NULL)
                {
                    tem->prev->next = p;
                }
                else
                {
                    head = p;
                }
                p->prev = tem->prev;
                free(tem);
                printf("\n Node before %d deleted successfully\n", pos);
                return 0;
            }
            else
            {
                printf("\n Node before %d not found\n", pos);
                return 0;
            }
        }
        count++;
        p = p->next;
    }
    printf("\n Node before %d not found\n", pos);
    return 0;
}

int del_after()
{
    struct Node *p, *tem;
    int pos;
    if (head == NULL)
    {
        printf("\n List is empty\n");
        return 0;
    }
    printf("\nEnter the position of the node after which you want to delete: ");
    scanf("%d", &pos);
    int count = 1;
    p = head;
    while (p != NULL)
    {
        if (count == pos)
        {
            if (p->next != NULL)
            {
                tem = p->next;
                p->next = p->next->next;
                if (p->next != NULL)
                {
                    p->next->prev = p;
                }
                free(tem);
                printf("\n Node after %d deleted successfully\n", pos);
                return 0;
            }
            else
            {
                printf("\n Node after %d not found\n", pos);
                return 0;
            }
        }
        count++;
        p = p->next;
    }
    printf("\n Node after %d not found\n", pos);
    return 0;
}