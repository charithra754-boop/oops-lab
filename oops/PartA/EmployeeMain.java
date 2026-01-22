import java.util.*;

class Employee {
    String id, name;
    int age;
    double salary;

    public Employee(String id, String name, int age, double salary) {
        this.id = id; this.name = name; this.age = age; this.salary = salary;
    }
}

public class EmployeeMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Employee[] emp = new Employee[3];
        for (int i = 0; i < 3; i++) {
            System.out.println("Enter ID, Name, Age, Salary:");
            emp[i] = new Employee(sc.next(), sc.next(), sc.nextInt(), sc.nextDouble());
        }
        Arrays.sort(emp, Comparator.comparingInt(e -> e.age));
        for (Employee e : emp) 
            System.out.println("Name: " + e.name + " (Age: " + e.age + ")");
    }
}
