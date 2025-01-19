#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function prototypes
void initStack(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
void reverseStack(Stack* stack);
void printStack(Stack* stack);

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1; // Stack is empty
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 if stack is empty
    }
    return stack->arr[(stack->top)--];
}

// Peek the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Reverse the stack using another stack
void reverseStack(Stack* stack) {
    Stack tempStack;
    initStack(&tempStack);

    // Transfer elements from original stack to temporary stack
    while (!isEmpty(stack)) {
        int value = pop(stack);
        push(&tempStack, value);
    }

    // Transfer elements back to original stack (reversed order)
    while (!isEmpty(&tempStack)) {
        int value = pop(&tempStack);
        push(stack, value);
    }
}

// Print the contents of the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack;
    initStack(&stack);

    // Pushing elements into the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    printf("Original Stack:\n");
    printStack(&stack);

    // Reversing the stack
    reverseStack(&stack);

    printf("Reversed Stack:\n");
    printStack(&stack);

    // Testing peek, pop and isEmpty
    printf("Top element after reversal: %d\n", peek(&stack));
    printf("Popping element: %d\n", pop(&stack));
    printf("Stack after pop:\n");
    printStack(&stack);

    printf("Is stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}
