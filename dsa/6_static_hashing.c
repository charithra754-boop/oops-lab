#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int h[MAX] = {0};

void insert() {
    int key, i; printf("Val: "); scanf("%d", &key);
    for (i = 0; i < MAX; i++) {
        int idx = (key % MAX + i) % MAX;
        if (h[idx] == 0) { h[idx] = key; printf("Idx %d. Merci!\n", idx); return; }
        printf("Idx %d busy. Entschuldigung!\n", idx);
    }
    printf("Table Full! No vacancy!\n");
}

void search() {
    int key, i; printf("Search: "); scanf("%d", &key);
    for (i = 0; i < MAX; i++) {
        int idx = (key % MAX + i) % MAX;
        if (h[idx] == key) { printf("Found at %d. Encontrado!\n", idx); return; }
        if (h[idx] == 0) break;
    }
    printf("Not found. Mianhae.\n");
}

void display() {
    printf("Hash Table: \n");
    for (int i = 0; i < MAX; i++) {
        printf("Idx %d: ", i);
        if (h[i]) printf("%d\n", h[i]);
        else printf("-\n");
    }
}

int main() {
    int ch;
    printf("--- Static Hashing (Exam Q6) ---\n");
    while (1) {
        printf("\n1.Insert 2.Search 3.Display 4.Exit: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: exit(0);
        }
    }
}