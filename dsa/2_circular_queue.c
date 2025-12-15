#include <stdio.h>
#include <stdlib.h>

/*
 * THE CIRCULAR QUEUE
 * 
 * Why did the circular queue get dizzy?
 * Because it kept going around in circles! (I'll see myself out...)
 */

#define MAX 5

int q[MAX];
int f = -1, r = -1;

void enqueue(int val) {
    if ((r + 1) % MAX == f) {
        printf("Queue Overflow! It's full! Stop feeding it!\n");
    } else {
        if (f == -1) f = 0;
        r = (r + 1) % MAX;
        q[r] = val;
        printf("Inserted %d. Round and round we go.\n", val);
    }
}

void dequeue() {
    if (f == -1) {
        printf("Queue Underflow! Nothing to see here.\n");
    } else {
        printf("Deleted %d. It has left the circle of life.\n", q[f]);
        if (f == r) {
            f = -1;
            r = -1; // Resetting, like a glorious phoenix.
        } else {
            f = (f + 1) % MAX;
        }
    }
}

void display() {
    int i;
    if (f == -1) {
        printf("Queue is empty. Echo... echo...\n");
    } else {
        printf("Queue elements: ");
        for (i = f; i != r; i = (i + 1) % MAX) {
            printf("%d ", q[i]);
        }
        printf("%d\n", q[i]); // Print the last one
    }
}

int main() {
    int choice, val;
    printf("--- Circular Queue of Wonders ---\n");
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Val: "); scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Bad input. The queue judges you.\n");
        }
    }
    return 0;
}
