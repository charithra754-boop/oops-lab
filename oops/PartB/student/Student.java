package student;

public class Student {
    String usn, dept;
    int g1, g2, g3;

    public Student(String u, String d, int a, int b, int c) {
        usn = u; dept = d; g1 = a; g2 = b; g3 = c;
    }

    public void display() {
        System.out.println("\n--- 🎓 Student: " + usn + " ---");
        // Simple SGPA logic: Average of grades / 10.
        System.out.printf("Dept: %s | Grades: %d %d %d | SGPA: %.2f\n", dept, g1, g2, g3, (g1+g2+g3)/30.0);
    }
}