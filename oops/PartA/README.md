# Part A Lab Programs

## 1. Employee Details
**File:** `EmployeeMain.java`
```java
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
```

## 2. Bank Customer (Package)
**File:** `BankMain.java`
```java
import MyPack.BankCustomer;
import java.util.Scanner;

public class BankMain {
    public static void main(String[] args) {
        System.out.println("--- Bank System ---");
        Scanner sc = new Scanner(System.in);

        System.out.print("Name & Balance: ");
        new BankCustomer(sc.next(), sc.nextDouble()).display();
        
        sc.close();
    }
}
```
**File:** `MyPack/BankCustomer.java`
```java
package MyPack;

public class BankCustomer {
    String name;
    double bal;

    public BankCustomer(String n, double b) { name = n; bal = b; }

    public void display() {
        System.out.println("\n--- 🏦 Account: " + name + " 🏦 ---");
        System.out.printf("Balance: $%.2f (%s)\n", bal, bal > 1000 ? "Rich!" : "Saving...");
    }
}
```

## 3. Student Inheritance
**File:** `StudentInheritance.java`
```java
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

    void display() {
        int total = m1 + m2 + m3;
        System.out.printf("Student: %s (%s) Marks: %d %d %d Total: %d\n", name, usn, m1, m2, m3, total);
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
        System.out.printf("[UG] %s (%s) Sem:%d Marks: %d %d %d Total: %d\n", name, usn, ToS, m1, m2, m3, total);
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
        System.out.printf("[PG] %s (%s) Sem:%d Marks: %d %d %d Total: %d\n", name, usn, ToS, m1, m2, m3, total);
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
```

## 4. Stack Operation
**File:** `StackDemo.java`
```java
import java.util.Scanner;

class Stack {
    int[] stk;
    int top;
    final int SIZE = 10;

    Stack() {
        stk = new int[SIZE];
        top = -1;
    }

    void push(int item) {
        if (top == SIZE - 1) System.out.println("Stack Overflow!");
        else { stk[++top] = item; System.out.println("Pushed: " + item); }
    }

    int pop() {
        if (top == -1) { System.out.println("Stack Underflow!"); return -1; }
        else return stk[top--];
    }

    void display() {
        if (top == -1) { System.out.println("Stack Empty"); return; }
        System.out.print("Stack: ");
        for (int i = 0; i <= top; i++) System.out.print(stk[i] + " ");
        System.out.println();
    }
}

public class StackDemo {
    public static void main(String[] args) {
        Stack s1 = new Stack();
        Stack s2 = new Stack();

        System.out.println(">> Stack 1 Ops:");
        s1.push(10); s1.push(20);
        s1.display();
        System.out.println("Popped: " + s1.pop());

        System.out.println("\n>> Stack 2 Ops:");
        for(int i=1; i<=5; i++) s2.push(i*100);
        s2.display();
    }
}
```

## 5. AdvMath Package
**File:** `MathMain.java`
```java
import AdvMath.*;
import java.util.Scanner;

public class MathMain {
    public static void main(String[] args) {
        System.out.print("--- 🧮 Math Wiz --- \nEnter Angle (deg): ");
        Scanner sc = new Scanner(System.in);
        double rad = new AngleConverter().toRad(sc.nextDouble());
        System.out.printf("Result (sin+cos+tan): %.4f\n", new TrigAlgo().complexTrig(rad));
        sc.close();
    }
}
```
**File:** `AdvMath/TrigAlgo.java`
```java
package AdvMath;
public class TrigAlgo {
    public double complexTrig(double rad) { return Math.sin(rad) + Math.cos(rad) + Math.tan(rad); }
}
```
**File:** `AdvMath/AngleConverter.java`
```java
package AdvMath;
public class AngleConverter {
    public double toRad(double deg) { return Math.toRadians(deg); }
}
```

## 6. Area Interface
**File:** `AreaMain.java`
```java
import java.util.Scanner;
public class AreaMain {
    public static void main(String[] args) {
        System.out.println("--- 📐 Shape Calculator 📐 ---");
        Scanner sc = new Scanner(System.in);
        System.out.print("Rect (L W): ");
        Shape rect = new Rectangle(sc.nextDouble(), sc.nextDouble());
        System.out.print("Tri (B H): ");
        Shape tri = new Triangle(sc.nextDouble(), sc.nextDouble());
        System.out.println("Rect Area: " + rect.calculateArea());
        System.out.println("Tri Area : " + tri.calculateArea());
        sc.close();
    }
}
```
**File:** `Shape.java`
```java
public interface Shape { double calculateArea(); }
```
**File:** `Rectangle.java`
```java
public class Rectangle implements Shape {
    double l, w;
    public Rectangle(double l, double w) { this.l = l; this.w = w; }
    public double calculateArea() { return l * w; }
}
```
**File:** `Triangle.java`
```java
public class Triangle implements Shape {
    double b, h;
    public Triangle(double b, double h) { this.b = b; this.h = h; }
    public double calculateArea() { return 0.5 * b * h; }
}
```

## 7. Exception Handling
**File:** `ExceptionDemo.java`
```java
import java.util.Scanner;
public class ExceptionDemo {
    public static void main(String[] args) {
        System.out.println("--- 🚫 Error Trapper 🚫 ---");
        try {
            int[] arr = {1, 2, 3};
            System.out.println(arr[new Scanner(System.in).nextInt()]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Out of bounds! (Index 0-2 only)");
        } catch (Exception e) {
            System.out.println("Something went wrong: " + e);
        } finally {
            System.out.println("Done.");
        }
    }
}
```

# Viva Questions

## 1. Employee Details (Q1)
*   **Basic:** What is a class in Java? What are objects? How do you read input from the user in Java?
*   **Intermediate:** Explain the use of `Scanner` class. How does `Arrays.sort()` work? What is `Comparator.comparingInt()`?
*   **Advanced:** How would you handle a larger number of employees without hardcoding an array size? Discuss different sorting algorithms and their efficiency.

## 2. Bank Customer (Q2)
*   **Basic:** What is a package in Java? Why do we use them?
*   **Intermediate:** How do you create and use a custom package? What is a constructor? What is `printf()`?
*   **Advanced:** Explain access modifiers (`public`, `private`, `protected`, `default`) in the context of packages and classes. How would you ensure data encapsulation for `BankCustomer`?

## 3. Student Inheritance (Q3)
*   **Basic:** What is inheritance in OOP? What are superclass and subclass?
*   **Intermediate:** Explain `super()` keyword. How does method overriding work? What is polymorphism?
*   **Advanced:** Discuss the advantages and disadvantages of inheritance. When would you prefer composition over inheritance? Explain the use of `instanceof` operator and casting.

## 4. Stack Operation (Q4)
*   **Basic:** What is a Stack? Explain Push and Pop operations.
*   **Intermediate:** How do you implement a Stack using an array? What is Stack Overflow and Underflow?
*   **Advanced:** Compare array-based vs. linked list-based Stack implementations. How would you make the Stack generic (e.g., to store any type of object)?

## 5. AdvMath Package (Q5)
*   **Basic:** What is a package (repetition from Q2, but good to reinforce)? What are static methods?
*   **Intermediate:** How do you organize classes within a package? How do you import classes from another package?
*   **Advanced:** Explain the `Math` class in Java. Differentiate between `static` and non-`static` methods/variables.

## 6. Area Interface (Q6)
*   **Basic:** What is an interface in Java? Why do we use it?
*   **Intermediate:** How does a class implement an interface? Can an interface have method implementations in Java 8 and later?
*   **Advanced:** Compare and contrast abstract classes and interfaces. When would you choose one over the other? Explain multiple inheritance in Java (or lack thereof).

## 7. Exception Handling (Q7)
*   **Basic:** What is an exception? What are `try`, `catch`, and `finally` blocks?
*   **Intermediate:** Explain `ArrayIndexOutOfBoundsException`. What is the purpose of multiple `catch` blocks?
*   **Advanced:** Differentiate between checked and unchecked exceptions. When would you use `throw` and `throws`? Explain exception hierarchy in Java.
