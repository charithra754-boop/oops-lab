#include <stdio.h>
#include <stdlib.h>

/*
 * STATIC HASHING
 * 
 * We are mapping keys to homes. Sometimes the home is taken.
 * That's when we knock on the next door (Linear Probing).
 * 
 * Joke: I was going to tell a UDP joke, but you might not get it.
 * (This is a hashing program, but networking jokes are funny too).
 */

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {0}; // 0 indicates empty slot (assuming positive keys)

void insert() {
    int key, index, i, flag = 0;
    printf("Enter a value to insert: ");
    scanf("%d", &key);
    
    index = key % TABLE_SIZE;
    
    for (i = 0; i < TABLE_SIZE; i++) {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (h[probeIndex] == 0) {
            h[probeIndex] = key;
            printf("Key %d inserted at index %d.\n", key, probeIndex);
            flag = 1;
            break;
        }
    }
    
    if (flag == 0)
        printf("Table is full! No vacancy!\n");
}

void search() {
    int key, index, i, flag = 0;
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    index = key % TABLE_SIZE;
    
    for (i = 0; i < TABLE_SIZE; i++) {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (h[probeIndex] == key) {
            printf("Value %d found at index %d.\n", key, probeIndex);
            flag = 1;
            break;
        }
        if (h[probeIndex] == 0) break; // Optimization: Stop if empty slot found
    }
    
    if (flag == 0) printf("Value not found! It's playing hide and seek.\n");
}

void display() {
    int i;
    printf("\n--- Hash Table Contents ---\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (h[i] != 0) printf("%d\n", h[i]);
        else printf("-\\n");
    }
    printf("---------------------------\n");
}

int main() {
    int choice;
    printf("--- Static Hashing (Linear Probing) ---\n");
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
