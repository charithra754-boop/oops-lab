import java.util.Scanner;

class Student {
    String usn;
    String name;
    int m1, m2, m3;

    Student(String usn, String name, int m1, int m2, int m3) {
        this.usn = usn;
        this.name = name;
        this.m1 = m1;
        this.m2 = m2;
        this.m3 = m3;
    }

    // Common display method
    void display() {
        int total = m1 + m2 + m3;
        System.out.printf("Student: %s (%s) Marks: %d %d %d Total: %d%n", name, usn, m1, m2, m3, total);
    }
}

class UG_Student extends Student {
    int ToS; // Total No. of Semesters

    UG_Student(String usn, String name, int ToS, int m1, int m2, int m3) {
        super(usn, name, m1, m2, m3);
        this.ToS = ToS;
    }

    @Override
    void display() {
        int total = m1 + m2 + m3;
        System.out.printf("[UG] %s (%s) Sem:%d Marks: %d %d %d Total: %d%n", name, usn, ToS, m1, m2, m3, total);
    }
}

class PG_Student extends Student {
    int ToS;
    
    PG_Student(String usn, String name, int ToS, int m1, int m2, int m3) {
        super(usn, name, m1, m2, m3);
        this.ToS = ToS;
    }

    @Override
    void display() {
        int total = m1 + m2 + m3;
        System.out.printf("[PG] %s (%s) Sem:%d Marks: %d %d %d Total: %d%n", name, usn, ToS, m1, m2, m3, total);
    }
}

public class StudentInheritance {
    public static void main(String[] args) {
        System.out.println("--- 🎓 Student Records 🎓 ---");
        
        Student[] students = new Student[3];

        students[0] = new UG_Student("1MS23CS001", "Alice", 4, 80, 90, 85);
        students[1] = new PG_Student("1MS23SCS01", "Bob", 2, 88, 92, 95);
        students[2] = new UG_Student("1MS23CS002", "Charlie", 4, 70, 75, 80);

        System.out.println("\n--- Displaying Student Details ---");
        for (Student s : students) {
            s.display(); // Polymorphic call
        }
    }
}