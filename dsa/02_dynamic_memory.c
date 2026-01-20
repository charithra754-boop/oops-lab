#include <stdio.h>
#include <stdlib.h> // Required for malloc, calloc, realloc, free

int main() {
    int *ptr_m, *ptr_c;
    int num_elements = 3; // Initial small size for malloc
    int new_num_elements = 5; // New size for realloc

    printf("--- Simple Malloc & Realloc Demo ---\n");
    // Malloc: Allocate memory for 3 integers
    ptr_m = (int*)malloc(num_elements * sizeof(int));

    if (ptr_m == NULL) {
        printf("Malloc failed!\n");
        return 1;
    }

    printf("Malloc: Allocated for %d ints. Initializing with 1, 2, 3.\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        ptr_m[i] = i + 1;
        printf("%d ", ptr_m[i]);
    }
    printf("\n");

    // Realloc: Resize the memory block
    // It will expand the array to hold 5 integers
    ptr_m = (int*)realloc(ptr_m, new_num_elements * sizeof(int));

    if (ptr_m == NULL) {
        printf("Realloc failed!\n");
        return 1;
    }

    printf("Realloc: Resized to %d ints. Existing values preserved, new ones uninitialized (garbage).\n", new_num_elements);
    printf("Realloc: Content after resizing:\n");
    for (int i = 0; i < new_num_elements; i++) {
        printf("%d ", ptr_m[i]); // Shows old values + new garbage
    }
    printf("\n");
    
    // Free malloc'd/realloc'd memory
    free(ptr_m);
    printf("Memory freed after malloc/realloc.\n");
    printf("\n----------------------------------\n");

    printf("--- Simple Calloc Demo ---\n");
    // Calloc: Allocate memory for 5 integers and initialize all to zero
    ptr_c = (int*)calloc(num_elements, sizeof(int)); // Using original num_elements for simplicity

    if (ptr_c == NULL) {
        printf("Calloc failed!\n");
        return 1;
    }

    printf("Calloc: Allocated for %d ints. Automatically zero-initialized:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", ptr_c[i]); // Will print 0s
    }
    printf("\n");

    // Free calloc'd memory
    free(ptr_c);
    printf("Memory freed after calloc.\n");
    printf("\n--------------------------\n");

    return 0;
}
