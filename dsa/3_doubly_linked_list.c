#include <stdio.h>
#include <stdlib.h>

/*
 * DOUBLY LINKED LIST
 * 
 * It points forward, it points backward. It's the indecisive
 * data structure!
 * 
 * Joke: Why did the pointer break up with the variable?
 * Because there was no reference!
 */

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the front. It cuts the line!\n", data);
}

void insertEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at the end. Polite, waiting its turn.\n", data);
}

void insertPos(int data, int pos) {
    if (pos == 1) { insertFront(data); return; }
    
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
    
    if (temp == NULL) {
        printf("Position out of bounds! Are you imagining things?\n");
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) temp->next->prev = newNode;
        temp->next = newNode;
        printf("Inserted %d at position %d. Sneaky.\n", data, pos);
    }
}

void deleteFront() {
    if (head == NULL) { printf("List is empty!\n"); return; }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    printf("Deleted %d from front. It was too eager.\n", temp->data);
    free(temp);
}

void deleteEnd() {
    if (head == NULL) { printf("List is empty!\n"); return; }
    if (head->next == NULL) { deleteFront(); return; }
    
    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    printf("Deleted %d from end. The caboose is loose!\n", temp->data);
    free(temp);
}

void deletePos(int pos) {
    if (head == NULL) { printf("List empty!\n"); return; }
    if (pos == 1) { deleteFront(); return; }
    
    struct Node *temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) temp = temp->next;
    
    if (temp == NULL) {
        printf("Invalid position. You can't delete what doesn't exist!\n");
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) temp->next->prev = temp->prev;
        printf("Deleted %d from pos %d. Poof! Gone.\n", temp->data, pos);
        free(temp);
    }
}

void display() {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, val, pos;
    printf("--- Doubly Linked List of Doom ---\n");
    while (1) {
        printf("\n1. Ins Front\n2. Ins End\n3. Ins Pos\n4. Del Front\n5. Del End\n6. Del Pos\n7. Display\n8. Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Val: "); scanf("%d", &val); insertFront(val); break;
            case 2: printf("Val: "); scanf("%d", &val); insertEnd(val); break;
            case 3: printf("Val: "); scanf("%d", &val); printf("Pos: "); scanf("%d", &pos); insertPos(val, pos); break;
            case 4: deleteFront(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Pos: "); scanf("%d", &pos); deletePos(pos); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Wrong choice.\n");
        }
    }
    return 0;
}
