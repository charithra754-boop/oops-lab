#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert_begin() {
    int val;
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory not available\n");
        return;
    }
    printf("Enter value to insert at beginning: ");
    scanf("%d", &val);
    ptr->data = val;
    ptr->prev = NULL;
    ptr->next = head;
    
    if (head != NULL) {
        head->prev = ptr;
    }
    head = ptr;
    printf("%d inserted at beginning.\n", val);
}

void insert_end() {
    int val;
    struct Node *ptr, *temp;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory not available\n");
        return;
    }
    printf("Enter value to insert at end: ");
    scanf("%d", &val);
    ptr->data = val;
    ptr->next = NULL;
    
    if (head == NULL) {
        ptr->prev = NULL;
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    printf("%d inserted at end.\n", val);
}

void delete_begin() {
    struct Node *ptr;
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        ptr = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("Deleted element: %d\n", ptr->data);
        free(ptr);
    }
}

void delete_end() {
    struct Node *ptr, *temp;
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        ptr = temp;
        temp->prev->next = NULL;
        printf("Deleted element: %d\n", ptr->data);
        free(ptr);
    }
}

void display() {
    struct Node *ptr;
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        ptr = head;
        printf("List elements: ");
        while (ptr != NULL) {
            printf("%d <-> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: delete_begin(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
