#include <stdio.h>
#include <stdlib.h>

// typedef allows using 'Node' instead of 'struct Node'
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createnode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_begin() {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);
    Node *newNode = createnode(data);
    
    newNode->next = head;
    
    if (head != NULL) head->prev = newNode;
    head = newNode;
    printf("Inserted %d at begin.\n", newNode->data);
}

void insert_end() {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);
    Node *newNode = createnode(data);
    
    if (head == NULL) {
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
    Node *temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    
    printf("Deleted %d\n", temp->data);
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List Empty.\n");
        return;
    }
    Node *temp = head;
    if (temp->next == NULL) { // Only one node
        head = NULL;
        printf("Deleted %d\n", temp->data);
        free(temp);
    } else {
        while (temp->next != NULL) temp = temp->next;
        temp->prev->next = NULL;
        printf("Deleted %d\n", temp->data);
        free(temp);
    }
}

void display() {
    Node *temp = head;
    if (temp == NULL) printf("List Empty.\n");
    else {
        printf("List: ");
        while (temp != NULL) {
            printf("%d <-> ", temp->data);
            temp = temp->next;
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