#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

void insert() {
    int val;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Circular Queue Overflow!\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);
    
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        if (rear == MAX - 1) rear = 0;
        else rear++;
    }
    cqueue[rear] = val;
    printf("%d inserted.\n", val);
}

void delete_element() {
    if (front == -1) {
        printf("Circular Queue Underflow!\n");
        return;
    }
    printf("Deleted element: %d\n", cqueue[front]);
    
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        if (front == MAX - 1) front = 0;
        else front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", cqueue[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("%d ", cqueue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert(); break;
            case 2: delete_element(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
