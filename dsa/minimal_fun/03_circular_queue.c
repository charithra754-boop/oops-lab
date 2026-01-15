#include <stdio.h>
#define SIZE 5

// --- TOPIC 6: CIRCULAR QUEUE ---
// Like a carousel! No wasted seats.
typedef struct {
    int items[SIZE];
    int front, rear;
} Carousel;

void init(Carousel *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Carousel *q) {
    if ((q->front == 0 && q->rear == SIZE - 1) || (q->front == q->rear + 1)) return 1;
    return 0;
}

int isEmpty(Carousel *q) {
    if (q->front == -1) return 1;
    return 0;
}

void enqueue(Carousel *q, int element) {
    if (isFull(q)) {
        printf("Carousel Full! Wait for the next ride.\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = element;
        printf("Inserted %d at pos %d\n", element, q->rear);
    }
}

int dequeue(Carousel *q) {
    if (isEmpty(q)) {
        printf("Carousel Empty! Ghost town.\n");
        return -1;
    } else {
        int element = q->items[q->front];
        if (q->front == q->rear) { // Reset if last element
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        return element;
    }
}

void display(Carousel *q) {
    if (isEmpty(q)) {
        printf("Empty!\n");
        return;
    }
    printf("Carousel: ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % SIZE)
        printf("%d ", q->items[i]);
    printf("%d\n", q->items[i]);
}

int main() {
    printf("\n=== CIRCULAR QUEUE (CAROUSEL) ===\n");
    Carousel q;
    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5); // Full now
    
    display(&q);
    
    printf("Removed: %d\n", dequeue(&q));
    enqueue(&q, 6); // Wraps around!
    
    display(&q);
    return 0;
}
