#include <stdio.h>

// typedef makes the code cleaner: 'Student' instead of 'struct Student'
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

int main() {
    int numStudents;
    printf("Structure Demo - Multiple Students\n");
    
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Basic validation for number of students
    if (numStudents <= 0) {
        printf("Number of students must be positive.\n");
        return 1;
    }

    // Declare an array of Student structures
    // Using a VLA (Variable Length Array) - C99 standard
    Student students[numStudents]; 

    printf("\nEnter details for %d students:\n", numStudents);
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &students[i].id);
        
        printf("Enter Name: ");
        scanf("%s", students[i].name); // Be cautious with scanf for strings, may lead to buffer overflow if input is too long
        
        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\n--- Student Details ---\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    return 0;
}