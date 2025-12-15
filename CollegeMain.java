import student.Student;
import staff.Staff;
import java.util.Scanner;

public class CollegeMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("--- 🏫 College Admin 🏫 ---");

        System.out.println("Enter Student (USN Dept G1 G2 G3):");
        new Student(sc.next(), sc.next(), sc.nextInt(), sc.nextInt(), sc.nextInt()).display();

        System.out.println("\nEnter Staff (ID Name Role Subject):");
        new Staff(sc.next(), sc.next(), sc.next(), sc.next()).display();
        
        sc.close();
    }
}