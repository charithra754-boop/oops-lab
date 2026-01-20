#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

int stack[MAX];
int top = -1; // Initialize top to -1 (empty stack)

// Function to push an element onto the stack
void push() {
    int val;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        printf("%d pushed onto stack.\n", val);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
