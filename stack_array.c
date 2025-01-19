#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

// Stack structure
int stack[MAX];
int top = -1; // Initialize top as -1, indicating an empty stack

// Function to check if the stack is empty
int isEmpty() {
    if (top == -1) {
        return 1; // Stack is empty
    }
    return 0; // Stack is not empty
}

// Function to check if the stack is full
int isFull() {
    if (top == MAX - 1) {
        return 1; // Stack is full
    }
    return 0; // Stack is not full
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack overflow! Unable to push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d to stack\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow! Stack is empty.\n");
        return -1; // Return -1 for error case
    } else {
        int poppedValue = stack[top];
        top--;
        printf("Popped %d from stack\n", poppedValue);
        return poppedValue;
    }
}

// Function to display the contents of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack contents: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function to test stack operations
int main() {
    int choice, value;
    
    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value); 
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty()) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
