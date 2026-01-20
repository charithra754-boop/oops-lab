#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, i;

    printf("Dynamic Memory Allocation Demo\n");
    printf("------------------------------\n");

    // 1. MALLOC: Allocate memory for 'n' integers
    printf("Enter number of elements for malloc: ");
    scanf("%d", &n);

    // allocate memory using malloc (memory is uninitialized)
    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize and display elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements in array (malloc): ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 2. REALLOC: Resize the memory block
    int new_n;
    printf("\nEnter new size for realloc: ");
    scanf("%d", &new_n);

    // Resize memory using realloc
    arr = (int*)realloc(arr, new_n * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // If new size is larger, initialize new elements
    if (new_n > n) {
        printf("Enter %d more elements:\n", new_n - n);
        for(i = n; i < new_n; i++) {
            scanf("%d", &arr[i]);
        }
    }

    printf("Elements in array (realloc): ");
    for(i = 0; i < new_n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 3. FREE: Deallocate memory
    free(arr);
    printf("\nMemory freed successfully using free().\n");
    
    // 4. CALLOC: Allocate and zero-initialize memory
    printf("\nDemonstrating calloc (allocates and initializes to 0):\n");
    printf("Enter number of elements for calloc: ");
    scanf("%d", &n);
    
    arr = (int*)calloc(n, sizeof(int));
    
     if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Elements in array (calloc - should be all 0): ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return 0;
}
