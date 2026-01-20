#include <stdio.h>

int main() {
    // Declare an integer variable 'num' and initialize it to 10
    int num = 10;
    
    // Declare a pointer 'ptr' and store the address of 'num' in it
    int *ptr = &num;

    printf("Pointer Operations Demo:\n");
    printf("------------------------\n");

    // Display the value of 'num' directly
    printf("Value of num: %d\n", num);
    
    // Display the address of 'num'
    printf("Address of num: %p\n", &num);
    
    // Display the value stored in 'ptr' (which is the address of 'num')
    printf("Value of ptr: %p\n", ptr);
    
    // Dereference 'ptr' to get the value pointed to (value of 'num')
    printf("Value pointed to by ptr (*ptr): %d\n", *ptr);

    printf("\nPointer Arithmetic:\n");
    
    // Increment the pointer. Since it's an int pointer, it moves by sizeof(int) bytes (usually 4)
    printf("Original ptr: %p\n", ptr);
    ptr++; 
    printf("ptr after increment (ptr++): %p\n", ptr);
    
    // Decrement the pointer back to the original address
    ptr--;
    printf("ptr after decrement (ptr--): %p\n", ptr);

    printf("\nPointers and Arrays:\n");
    printf("--------------------\n");
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    int *arrPtr = arr; // Point to the start of the array

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arrPtr + i)); // Accessing array elements using pointer arithmetic
        sum += *(arrPtr + i);
    }
    printf("\nSum of array elements using pointer: %d\n", sum);

    return 0;
}
