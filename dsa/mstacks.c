#include <stdio.h>
#include <stdlib.h>

/*
 * WELCOME TO THE DUAL STACK EXTRAVAGANZA!
 * 
 * Fun Fact: Did you know that stacks are like pancakes? 
 * If you try to eat the bottom one first, you make a mess. 
 * Unless you are a wizard. Are you a wizard?
 */

#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int data) {
    if (top1 < top2 - 1) {
        arr[++top1] = data;
        printf("Pushed %d to Stack 1. It's cozy in there.\n", data);
    } else {
        printf("Stack Overflow! The stacks have collided! It's a disaster!\n");
    }
}

void push2(int data) {
    if (top1 < top2 - 1) {
        arr[--top2] = data;
        printf("Pushed %d to Stack 2. Living on the edge (of the array).\n", data);
    } else {
        printf("Stack Overflow! No more room at the inn!\n");
    }
}

void pop1() {
    if (top1 >= 0) {
        printf("Popped %d from Stack 1. Bye bye!\n", arr[top1--]);
    } else {
        printf("Stack 1 Underflow! It's empty, like my fridge.\n");
    }
}

void pop2() {
    if (top2 < MAX) {
        printf("Popped %d from Stack 2. See ya later!\n", arr[top2++]);
    } else {
        printf("Stack 2 Underflow! Ghost town over here.\n");
    }
}

void display() {
    int i;
    printf("\n--- Stack 1 (The Lefties) ---\n");
    for (i = 0; i <= top1; i++) printf("%d ", arr[i]);
    printf("\n");
    
    printf("\n--- Stack 2 (The Righties) ---\n");
    for (i = MAX - 1; i >= top2; i--) printf("%d ", arr[i]);
    printf("\n-----------------------------\n");
}

int main() {
    int choice, val;
    printf("--- Two Stacks, One Array ---\n");
    while (1) {
        printf("\n1. Push Stack 1\n2. Pop Stack 1\n3. Push Stack 2\n4. Pop Stack 2\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); push1(val); break;
            case 2: pop1(); break;
            case 3: printf("Enter value: "); scanf("%d", &val); push2(val); break;
            case 4: pop2(); break;
            case 5: display(); break;
            case 6: printf("Exiting... Remember, LIFO is life.\n"); exit(0);
            default: printf("Invalid choice. Try again, human.\n");
        }
    }
    return 0;
}
