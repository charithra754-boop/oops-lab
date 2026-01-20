#include <stdio.h>

// Define a structure to hold student details
struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct Student s;

    printf("Structure Demo (Student Management)\n");
    printf("-----------------------------------\n");

    // Read student details from user
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    
    printf("Enter Student Name: ");
    scanf("%s", s.name); // Simple string input
    
    printf("Enter Student Marks: ");
    scanf("%f", &s.marks);

    // Display the details
    printf("\nStudent Details Display:\n");
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}
