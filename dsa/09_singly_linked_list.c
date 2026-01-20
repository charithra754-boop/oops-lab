#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_begin() {
    int val;
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &val);
    ptr->data = val;
    ptr->next = head;
    head = ptr;
    printf("%d inserted at beginning.\n", val);
}

void insert_end() {
    int val;
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    printf("Enter value: ");
    scanf("%d", &val);
    ptr->data = val;
    ptr->next = NULL;
    
    if (head == NULL) head = ptr;
    else {
        while(temp->next != NULL) temp = temp->next;
        temp->next = ptr;
    }
    printf("%d inserted at end.\n", val);
}

void insert_pos() {
    int val, pos, i;
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    printf("Enter position (1-based): ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);
    ptr->data = val;

    if (pos == 1) {
        ptr->next = head;
        head = ptr;
    } else {
        for(i=1; i<pos-1; i++) {
            if(temp == NULL) { printf("Position out of range.\n"); return; }
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    printf("%d inserted at pos %d.\n", val, pos);
}

void delete_begin() {
    if (head == NULL) printf("List Empty.\n");
    else {
        struct Node *ptr = head;
        head = head->next;
        printf("Deleted: %d\n", ptr->data);
        free(ptr);
    }
}

void delete_end() {
    if (head == NULL) printf("List Empty.\n");
    else if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        printf("Deleted: %d\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void delete_pos() {
    int pos, i;
    if (head == NULL) { printf("List Empty.\n"); return; }
    printf("Enter position (1-based): ");
    scanf("%d", &pos);
    
    if (pos == 1) {
        struct Node *ptr = head;
        head = head->next;
        printf("Deleted: %d\n", ptr->data);
        free(ptr);
    } else {
        struct Node *temp = head;
        struct Node *ptr;
        for(i=1; i<pos-1; i++) {
            if(temp->next == NULL) { printf("Position out of range.\n"); return; }
            temp = temp->next;
        }
        if(temp->next == NULL) { printf("Position out of range.\n"); return; }
        ptr = temp->next;
        temp->next = ptr->next;
        printf("Deleted: %d\n", ptr->data);
        free(ptr);
    }
}

void display() {
    struct Node *temp = head;
    if(temp == NULL) printf("List is Empty.\n");
    else {
        printf("Elements: ");
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int ch;
    while(1) {
        printf("\nSLL Menu:\n1.Ins Begin\n2.Ins End\n3.Ins Pos\n4.Del Begin\n5.Del End\n6.Del Pos\n7.Display\n8.Exit\nChoice: ");
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
            default: printf("Invalid\n");
        }
    }
    return 0;
}
