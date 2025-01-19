#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to perform bubble sort on the linked list
void bubbleSort(struct Node* head) {
    if (head == NULL) {
        return;
    }
    
    int swapped;
    struct Node* ptr1;
    struct Node* ptr2 = NULL;
    
    // Traverse the list and perform bubble sort
    do {
        swapped = 0;
        ptr1 = head;
        
        // Traverse the list from head to the second last node
        while (ptr1->next != ptr2) {
            // Swap if the current node's data is greater than the next node's data
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        // After each pass, the last node is sorted, so reduce the range
        ptr2 = ptr1;
    } while (swapped); // Repeat until no swaps are made
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate bubble sort using a linked list
int main() {
    struct Node* head = NULL;
    
    // Insert some elements into the linked list
    appendNode(&head, 5);
    appendNode(&head, 1);
    appendNode(&head, 4);
    appendNode(&head, 2);
    appendNode(&head, 3);
    
    printf("Original List: ");
    printList(head);
    
    // Perform bubble sort
    bubbleSort(head);
    
    printf("Sorted List: ");
    printList(head);
    
    return 0;
}
