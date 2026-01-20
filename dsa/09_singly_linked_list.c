#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert_begin() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at begin.\n", newNode->data);
}

void insert_end() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    
    if (head == NULL) head = newNode;
    else {
        Node *temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at end.\n", newNode->data);
}

void insert_pos() {
    int pos, i;
    printf("Enter pos (1-based) & value: ");
    scanf("%d", &pos);
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    scanf("%d", &newNode->data);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *temp = head;
        for(i=1; i<pos-1 && temp!=NULL; i++) temp = temp->next;
        
        if(temp == NULL) printf("Invalid pos.\n");
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void delete_begin() {
    if (head == NULL) printf("Empty.\n");
    else {
        Node *ptr = head;
        head = head->next;
        printf("Deleted %d\n", ptr->data);
        free(ptr);
    }
}

void delete_end() {
    if (head == NULL) printf("Empty.\n");
    else if (head->next == NULL) {
        printf("Deleted %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        Node *temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        printf("Deleted %d\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_pos() {
    int pos, i;
    if (head == NULL) { printf("Empty.\n"); return; }
    printf("Enter pos: ");
    scanf("%d", &pos);
    
    if (pos == 1) {
        Node *ptr = head;
        head = head->next;
        printf("Deleted %d\n", ptr->data);
        free(ptr);
    } else {
        Node *temp = head;
        for(i=1; i<pos-1 && temp->next!=NULL; i++) temp = temp->next;
        
        if(temp->next == NULL) printf("Invalid pos.\n");
        else {
            Node *ptr = temp->next;
            temp->next = ptr->next;
            printf("Deleted %d\n", ptr->data);
            free(ptr);
        }
    }
}

void display() {
    Node *temp = head;
    printf("List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int ch;
    while(1) {
        printf("\nSLL Menu: 1.InsBeg 2.InsEnd 3.InsPos 4.DelBeg 5.DelEnd 6.DelPos 7.Show 8.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: display(); break;
            case 8: exit(0);
        }
    }
    return 0;
}