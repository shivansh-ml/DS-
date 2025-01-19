/*
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next; // changed int to struct Node*
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
        printf("\n List is empty\n");
    }
    else
    {
        printf("Enter the number you want to  insert before\n");
        scanf("%d", &a);
        ptr = head;
        prev = NULL;
        while (ptr != NULL)
        {
            if (ptr->data == a)
            {
                tem = (struct Node *)malloc(sizeof(struct Node));
                printf("Enter the data\n");
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
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if (count == 0)
        {
            printf("Number you searched for is not in the list\n");
        }
    }
}*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL, *temp;
int count = 0;

int listcreation();
int display();
int del_beg();
int del_end();
int del_after();
int del_before();

int main() {
    int i = 0, ch;
    while (i == 0) {
        printf("\n\n\tDoubly Linked List Menu\n");
        printf("Enter 1 for linked list creation\n");
        printf("Enter 2 for  deletion at beginning\n");
        printf("Enter 3 for deletion at end\n");
        printf("Enter 4 for deletion after a number\n");
        printf("Enter 5 for deletion before a number\n");
        printf("Enter 6 for display\n");
        printf("Enter 7 for exiting the program\n");
        scanf("%d", &ch);
        switch (ch) {
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

int listcreation() {
    if (head == NULL) {
        head = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node 1: ");
        scanf("%d", &head->data);
        head->next = NULL;
        head->prev = NULL;
        temp = head;
        count++;
    } else {
        struct Node* p;
        p = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", count + 1);
        scanf("%d", &p->data);
        p->prev = temp;
        temp->next = p;
        p->next = NULL;
        temp = p;
        count++;
    }
}

int display() {
    struct Node* p;
    p = head;
    if (head == NULL) {
        printf("\n List is empty\n");
    } else {
        p = head;
        printf("The data is ");
        while (p != NULL) {
            printf("->%d ", p->data);
            p = p->next;
        }
    }
}

int del_beg() {
    if (head == NULL) {
        printf("\n List is empty\n");
    } else {
        struct Node* tem;
        tem = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(tem);
    }
}

int del_end() {
    struct Node* p, *tem;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        p = head;
        while (p != NULL) {
            if (p->next == NULL) {
                temp = p;
                if (p->prev != NULL) {
                    p->prev->next = NULL;
                } else {
                    head = NULL;
                }
                free(temp);
                return 0;
            }
            p = p->next;
        }
    }
}

int del_before() {
    struct Node* p, *q, *tem;
    int pos;
    if (head == NULL) {
        printf("\n List is empty\n");
    } else {
        printf("\nEnter the position of the node to be deleted: ");
        scanf("%d", &pos);
        p = head;
        while (p != NULL) {
            if (p->data == pos) {
                if (p->prev != NULL) {
                    tem = p->prev;
                    if (tem->prev != NULL) {
                        tem->prev->next = p;
                    } else {
                        head = p;
                    }
                    p->prev = tem->prev;
                    free(tem);
                    printf("\n Node with data %d deleted successfully\n", pos);
                } else {
                    printf("\n No node to delete\n");
                }
                return 0;
            }
            p = p->next;
        }
        printf("\n Node with data %d not found\n", pos);
    }
}

int del_after() {
    struct Node* p, *tem;
    int pos;
    if (head == NULL) {
        printf("\n List is empty\n");
    } else {
        printf("\nEnter the position of the node after which you want to delete: ");
        scanf("%d", &pos);
        p = head;
        while (p != NULL) {
            if (p->data == pos) {
                if (p->next != NULL) {
                    tem = p->next;
                    p->next = p->next->next;
                    if (p->next != NULL) {
                        p->next->prev = p;
                    }
                    free(tem);
                    printf("\n Node after %d deleted successfully\n", pos);
                } else {
                    printf("\n No node to delete\n");
                }
                return 0;
            }
            p = p->next;
        }
        printf("\n Node with data %d not found\n", pos);
    }
}