#include <stdio.h>
#include <stdlib.h>

// Structure for the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to remove duplicates from the sorted doubly linked list
void removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // Duplicate found, remove the next node
            struct Node* temp = current->next;
            current->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = current;
            }
            free(temp);
        } else {
            // Move to the next node
            current = current->next;
        }
    }
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Append some data to the doubly linked list
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Original list: ");
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
