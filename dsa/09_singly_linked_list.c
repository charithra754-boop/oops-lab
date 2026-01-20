#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_begin() {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning.\n", data);
}

void insert_end() {
    int data;
    printf("Enter value: ");
    scanf("%d", &data);
    Node *newNode = createNode(data);
    if (!head) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at end.\n", data);
}

void insert_at_position() {
    int position, data, i;
    printf("Enter Position and Value: ");
    scanf("%d%d", &position, &data);
    
    if (position == 1) {
        Node *newNode = createNode(data);
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", data, position);
        return;
    }
    
    Node *temp = head;
    for (i = 1; i < position - 1 && temp; i++) {
        temp = temp->next;
    }
    
    if (temp) {
        Node *newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted %d at position %d.\n", data, position);
    } else {
        printf("Invalid position!\n");
    }
}

void delete_begin() {
    if (!head) {
        printf("List is Empty.\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void delete_end() {
    if (!head) {
        printf("List is Empty.\n");
        return;
    }
    if (!head->next) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next) temp = temp->next;
    printf("Deleted %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void delete_at_position() {
    int position, i;
    printf("Enter Position: ");
    scanf("%d", &position);
    
    if (!head) {
        printf("List is Empty.\n");
        return;
    }
    
    if (position == 1) {
        delete_begin();
        return;
    }
    
    Node *temp = head;
    for (i = 1; i < position - 1 && temp->next; i++) {
        temp = temp->next;
    }
    
    if (temp->next) {
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        printf("Deleted %d from position %d.\n", nodeToDelete->data, position);
        free(nodeToDelete);
    } else {
        printf("Invalid position!\n");
    }
}

void display() {
    if (!head) {
        printf("List is Empty.\n");
        return;
    }
    Node *temp = head;
    printf("List: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nSingly Linked List Menu:\n");
        printf("1. Insert Begin\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Begin\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_at_position(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_at_position(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
