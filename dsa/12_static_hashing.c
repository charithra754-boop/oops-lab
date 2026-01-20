#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void init() {
    for(int i=0; i<TABLE_SIZE; i++) hashTable[i] = -1; // -1 indicates empty
}

void insert() {
    int val, key, index, i;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    key = val % TABLE_SIZE;
    
    // Linear Probing
    for(i=0; i<TABLE_SIZE; i++) {
        index = (key + i) % TABLE_SIZE;
        if(hashTable[index] == -1) {
            hashTable[index] = val;
            printf("%d inserted at index %d\n", val, index);
            return;
        }
    }
    printf("Hash Table is Full!\n");
}

void search() {
    int val, key, index, i;
    printf("Enter value to search: ");
    scanf("%d", &val);
    key = val % TABLE_SIZE;
    
    for(i=0; i<TABLE_SIZE; i++) {
        index = (key + i) % TABLE_SIZE;
        if(hashTable[index] == val) {
            printf("Found %d at index %d\n", val, index);
            return;
        }
        if(hashTable[index] == -1) break; // Optimization: Stop if empty slot found
    }
    printf("Value %d not found.\n", val);
}

void display() {
    printf("Hash Table:\n");
    for(int i=0; i<TABLE_SIZE; i++) {
        if(hashTable[i] != -1) printf("[%d] -> %d\n", i, hashTable[i]);
        else printf("[%d] -> \n", i);
    }
}

int main() {
    int choice;
    init();
    
    while(1) {
        printf("\nHash Table (Static Hashing) Menu:\n1. Insert\n2. Search\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
