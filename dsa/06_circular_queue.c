#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int cqueue[MAX];
int front = -1, rear = -1;

void insert() {
    int val;
    // Rule for Full: The very next spot after REAR is where FRONT is sitting
    if ((rear + 1) % MAX == front) {
        printf("Queue Full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &val);

    if (front == -1) front = 0; // First element ever

    // The Magic Line: Instead of if-else, just use math
    rear = (rear + 1) % MAX; 
    
    cqueue[rear] = val;
    printf("%d inserted.\n", val);
}

void delete_element() {
    if (front == -1) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Deleted: %d\n", cqueue[front]);

    if (front == rear) {
        // Queue is now empty after this deletion
        front = rear = -1;
    } else {
        // The Magic Line: Wrap front around automatically
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Empty.\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break; // Stop once we've printed the last item
        i = (i + 1) % MAX;    // Move to next slot circularly
    }
    printf("\n");
}
