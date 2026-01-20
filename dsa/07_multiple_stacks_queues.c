#include <stdio.h>
#include <stdlib.h>

int *stack;
int size = 10;
int top1 = -1;
int top2;

void init() {
    stack = (int*)malloc(size * sizeof(int));
    if (!stack) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    top2 = size;
    printf("Initialized stack with size %d\n", size);
}

void resize() {
    int old_size = size;
    size *= 2;
    int *new_stack = (int*)realloc(stack, size * sizeof(int));
    if (!new_stack) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    stack = new_stack;
    
    int i;
    for (i = old_size - 1; i >= top2; i--) {
        stack[i + old_size] = stack[i];
    }
    
    top2 += old_size;
    printf("Stack resized from %d to %d.\n", old_size, size);
}

void push1() {
    int val;
    if (top1 == top2 - 1) {
        resize();
    }
    
    printf("Enter value for Stack 1: ");
    scanf("%d", &val);
    top1++;
    stack[top1] = val;
    printf("%d pushed to Stack 1.\n", val);
}

void push2() {
    int val;
    if (top1 == top2 - 1) {
        resize();
    }
    
    printf("Enter value for Stack 2: ");
    scanf("%d", &val);
    top2--;
    stack[top2] = val;
    printf("%d pushed to Stack 2.\n", val);
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
    if (top2 < size) {
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
    if (top2 < size) {
        printf("Stack 2: ");
        for (i = top2; i < size; i++) printf("%d ", stack[i]);
        printf("\n");
    } else {
        printf("Stack 2 is empty.\n");
    }
}

int main() {
    init();
    int choice;
    while (1) {
        printf("\nMultiple Stacks (Dynamic) Menu:\n");
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
            case 7: free(stack); exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}