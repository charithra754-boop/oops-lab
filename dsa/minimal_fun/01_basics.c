#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- TOPIC 3: Structures ---
typedef struct {
    char name[50];
    int hunger_level;
} Cat;

void topic_1_pointers() {
    printf("\n--- 1. POINTERS: The Magic Wands ---\n");
    int treasure = 100;
    int *map = &treasure;
    
    printf("Treasure location (address): %p\n", (void*)map);
    printf("Treasure value: %d\n", *map);
    
    *map = 999; // Modifying via pointer
    printf("New treasure value (after magic): %d\n", treasure);
}

void topic_2_dynamic_memory() {
    printf("\n--- 2. DYNAMIC MEMORY: The Expanding Backpack ---\n");
    
    // Malloc
    int *party_list = (int*)malloc(2 * sizeof(int));
    if (!party_list) return;
    
    party_list[0] = 1; 
    party_list[1] = 2;
    printf("Malloc: Invited guests 1 and 2.\n");

    // Calloc (cleans the room first)
    int *clean_room = (int*)calloc(2, sizeof(int));
    printf("Calloc: Room initialized to %d and %d.\n", clean_room[0], clean_room[1]);
    free(clean_room);

    // Realloc
    party_list = (int*)realloc(party_list, 4 * sizeof(int));
    party_list[2] = 3; 
    party_list[3] = 4;
    printf("Realloc: Expanded party to 4 guests!\n");
    
    free(party_list);
    printf("Free: Party over, memory released.\n");
}

void topic_3_structures() {
    printf("\n--- 3. STRUCTURES: Cat Blueprints ---\n");
    Cat my_cat;
    strcpy(my_cat.name, "Whiskers");
    my_cat.hunger_level = 9000;
    
    printf("Cat: %s, Hunger: %d/10\n", my_cat.name, my_cat.hunger_level);
}

int main() {
    printf("=== BASICS OF C PLAYGROUND ===\n");
    topic_1_pointers();
    topic_2_dynamic_memory();
    topic_3_structures();
    return 0;
}
