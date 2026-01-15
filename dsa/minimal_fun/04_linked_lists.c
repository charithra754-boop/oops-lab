#include <stdio.h>
#include <stdlib.h>

// --- TOPIC 9: SINGLY LINKED LIST ---
// A conga line! Everyone holds the shoulders of the person in front.
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// --- TOPIC 8: DOUBLY LINKED LIST ---
// Holding hands with both neighbors!
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// --- Singly Helpers ---
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_singly(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
    printf("[Singly] Added %d to the conga line head.\n", data);
}

void delete_singly(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    printf("[Singly] %d left the conga line.\n", temp->data);
    free(temp);
}

// --- Doubly Helpers ---
DNode* create_dnode(int data) {
    DNode* new_node = (DNode*)malloc(sizeof(DNode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_doubly(DNode** head, int data) {
    DNode* new_node = create_dnode(data);
    new_node->next = *head;
    if (*head != NULL) (*head)->prev = new_node;
    *head = new_node;
    printf("[Doubly] Added %d (holding hands).\n", data);
}

int main() {
    printf("\n=== LINKED LISTS PLAYGROUND ===\n");

    // Singly
    Node* s_head = NULL;
    insert_singly(&s_head, 10);
    insert_singly(&s_head, 20);
    delete_singly(&s_head);

    // Doubly
    DNode* d_head = NULL;
    insert_doubly(&d_head, 100);
    insert_doubly(&d_head, 200);
    
    // Cleanup not shown for minimalism but remember to free!
    return 0;
}
