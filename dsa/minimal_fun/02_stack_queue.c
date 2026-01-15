#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// --- TOPIC 4: STACK (LIFO - Last In, First Out) ---
// Like a stack of pancakes!
typedef struct {
    int items[MAX];
    int top;
} PancakeStack;

void push(PancakeStack *s, int val) {
    if (s->top == MAX - 1) printf("Stack Overflow! Too many pancakes!\n");
    else s->items[++s->top] = val;
}

int pop(PancakeStack *s) {
    if (s->top == -1) { printf("Stack Underflow! No pancakes left :(\n"); return -1; }
    return s->items[s->top--];
}

// --- TOPIC 5: QUEUE (FIFO - First In, First Out) ---
// Like a line for movie tickets!
typedef struct {
    int items[MAX];
    int front, rear;
} TicketQueue;

void enqueue(TicketQueue *q, int val) {
    if (q->rear == MAX - 1) printf("Queue Full! Line is too long!\n");
    else {
        if (q->front == -1) q->front = 0;
        q->items[++q->rear] = val;
    }
}

int dequeue(TicketQueue *q) {
    if (q->front == -1) { printf("Queue Empty! No one in line.\n"); return -1; }
    int val = q->items[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1; // Reset
    return val;
}

// --- TOPIC 7: MULTIPLE STACKS ---
// Two stacks in one array (growing from ends)
typedef struct {
    int arr[MAX];
    int top1, top2;
} DualStack;

void push1(DualStack *ds, int val) {
    if (ds->top1 < ds->top2 - 1) ds->arr[++ds->top1] = val;
    else printf("Stack 1 Overflow! Crash into Stack 2!\n");
}

void push2(DualStack *ds, int val) {
    if (ds->top1 < ds->top2 - 1) ds->arr[--ds->top2] = val;
    else printf("Stack 2 Overflow! Crash into Stack 1!\n");
}

int main() {
    printf("\n=== STACKS & QUEUES PLAYGROUND ===\n");
    
    // 1. Stack Demo
    PancakeStack s = { .top = -1 };
    printf("\n[Stack] Cooking pancakes...\n");
    push(&s, 10); push(&s, 20);
    printf("[Stack] Ate pancake: %d\n", pop(&s));

    // 2. Queue Demo
    TicketQueue q = { .front = -1, .rear = -1 };
    printf("\n[Queue] People joining line...\n");
    enqueue(&q, 100); enqueue(&q, 200);
    printf("[Queue] Serving person: %d\n", dequeue(&q));

    // 3. Dual Stack Demo
    DualStack ds = { .top1 = -1, .top2 = MAX };
    printf("\n[DualStack] Filling from both ends...\n");
    push1(&ds, 1); push2(&ds, 99);
    printf("[DualStack] S1 Top: %d, S2 Top: %d\n", ds.arr[ds.top1], ds.arr[ds.top2]);

    return 0;
}
