#include <stdio.h>

// typedef makes the code cleaner: 'Student' instead of 'struct Student'
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

int main() {
    Student s; // No 'struct' keyword needed now

    printf("Structure Demo\n");
    
    printf("Enter ID: ");
    scanf("%d", &s.id);
    
    printf("Enter Name: ");
    scanf("%s", s.name);
    
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    printf("\nDetails: ID:%d | Name:%s | Marks:%.2f\n", s.id, s.name, s.marks);

    return 0;
}