#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1() {
    int val;
    if (top1 < top2 - 1) {
        printf("Enter value for Stack 1: ");
        scanf("%d", &val);
        top1++;
        stack[top1] = val;
        printf("%d pushed to Stack 1.\n", val);
    } else {
        printf("Stack Overflow!\n");
    }
}

void push2() {
    int val;
    if (top1 < top2 - 1) {
        printf("Enter value for Stack 2: ");
        scanf("%d", &val);
        top2--;
        stack[top2] = val;
        printf("%d pushed to Stack 2.\n", val);
    } else {
        printf("Stack Overflow!\n");
    }
}

void pop1() {
    if (top1 >= 0) {
        printf("Popped from Stack 1: %d\n", stack[top1]);
        top1--;
    } else {
        printf("Stack 1 Underflow!\n");
    }
}

void pop2() {
    if (top2 < MAX) {
        printf("Popped from Stack 2: %d\n", stack[top2]);
        top2++;
    } else {
        printf("Stack 2 Underflow!\n");
    }
}

void display1() {
    int i;
    if (top1 >= 0) {
        printf("Stack 1: ");
        for (i = top1; i >= 0; i--) printf("%d ", stack[i]);
        printf("\n");
    } else {
        printf("Stack 1 is empty.\n");
    }
}

void display2() {
    int i;
    if (top2 < MAX) {
        printf("Stack 2: ");
        for (i = top2; i < MAX; i++) printf("%d ", stack[i]);
        printf("\n");
    } else {
        printf("Stack 2 is empty.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMultiple Stacks Menu:\n");
        printf("1. Push Stack 1\n");
        printf("2. Pop Stack 1\n");
        printf("3. Display Stack 1\n");
        printf("4. Push Stack 2\n");
        printf("5. Pop Stack 2\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push1(); break;
            case 2: pop1(); break;
            case 3: display1(); break;
            case 4: push2(); break;
            case 5: pop2(); break;
            case 6: display2(); break;
            case 7: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
