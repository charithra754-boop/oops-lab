#include <stdio.h>
#include <stdlib.h>

// typedef allows using 'Node' instead of 'struct Node'
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

void insert_begin() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return;
    
    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) head->prev = newNode;
    head = newNode;
    printf("Inserted %d at begin.\n", newNode->data);
}

void insert_end() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) return;
    
    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end.\n", newNode->data);
}

void delete_begin() {
    if (head == NULL) {
        printf("List Empty.\n");
        return;
    }
    Node *ptr = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    
    printf("Deleted %d\n", ptr->data);
    free(ptr);
}

void delete_end() {
    if (head == NULL) {
        printf("List Empty.\n");
        return;
    }
    Node *ptr = head;
    if (ptr->next == NULL) { // Only one node
        head = NULL;
        printf("Deleted %d\n", ptr->data);
        free(ptr);
    } else {
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->prev->next = NULL;
        printf("Deleted %d\n", ptr->data);
        free(ptr);
    }
}

void display() {
    Node *ptr = head;
    if (ptr == NULL) printf("List Empty.\n");
    else {
        printf("List: ");
        while (ptr != NULL) {
            printf("%d <-> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int ch;
    while(1) {
        printf("\nDLL Menu:\n1.Ins Begin\n2.Ins End\n3.Del Begin\n4.Del End\n5.Display\n6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: delete_begin(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: exit(0);
        }
    }
    return 0;
}