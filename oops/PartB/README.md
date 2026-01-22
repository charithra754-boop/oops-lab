# Part B Lab Programs

## 1. Car Inheritance
**File:** `MyOwnAutoShop.java`
```java
class Car {
    int speed;
    double regularPrice;
    String color;

    public Car(int speed, double regularPrice, String color) {
        this.speed = speed;
        this.regularPrice = regularPrice;
        this.color = color;
    }

    double getSalePrice() {
        return regularPrice;
    }
}

class Truck extends Car {
    int weight;

    public Truck(int speed, double regularPrice, String color, int weight) {
        super(speed, regularPrice, color);
        this.weight = weight;
    }

    @Override
    double getSalePrice() {
        return super.getSalePrice() * (weight > 2000 ? 0.90 : 0.80);
    }
}

class Ford extends Car {
    int year;
    int manufacturerDiscount;

    public Ford(int speed, double regularPrice, String color, int year, int manufacturerDiscount) {
        super(speed, regularPrice, color);
        this.year = year;
        this.manufacturerDiscount = manufacturerDiscount;
    }

    @Override
    double getSalePrice() {
        return super.getSalePrice() - manufacturerDiscount;
    }
}

class Sedan extends Car {
    int length;

    public Sedan(int speed, double regularPrice, String color, int length) {
        super(speed, regularPrice, color);
        this.length = length;
    }

    @Override
    double getSalePrice() {
        return super.getSalePrice() * (length > 20 ? 0.95 : 0.90);
    }
}

public class MyOwnAutoShop {
    public static void main(String[] args) {
        System.out.println("--- MyOwnAutoShop (Inheritance Demo) ---");

        Sedan mySedan = new Sedan(120, 25000.0, "Blue", 22);
        System.out.println("Sedan Sale Price: $" + mySedan.getSalePrice());

        Ford myFord = new Ford(100, 30000.0, "Black", 2022, 2000);
        System.out.println("Ford Sale Price: $" + myFord.getSalePrice());

        Car myCar = new Car(90, 18000.0, "Red");
        System.out.println("Car Sale Price: $" + myCar.getSalePrice());

        Truck myTruck = new Truck(80, 45000.0, "Green", 2500);
        System.out.println("Truck Sale Price: $" + myTruck.getSalePrice());
    }
}
```

## 2. Vehicle Abstract Class
**File:** `VehicleAbstract.java`
```java
import java.util.Scanner;

abstract class Vehicle {
    boolean hashelmet;
    int yom; // year of manufacture

    abstract void getData();
    abstract void putData();

    public Vehicle(boolean h, int n) {
        this.hashelmet = h;
        this.yom = n;
    }

    public Vehicle(int n) { // For FourWheeler, default hashelmet to false
        this.hashelmet = false;
        this.yom = n;
    }
}

class TwoWheeler extends Vehicle {
    String Brand;
    int Cost;
    String EngineType;
    String Color;

    public TwoWheeler(int n) {
        super(true, n);
        this.Brand = ""; this.Cost = 0; this.EngineType = ""; this.Color = "";
    }

    public TwoWheeler(int year, String brand, int cost, String engine, String color) {
        super(true, year);
        this.Brand = brand; this.Cost = cost; this.EngineType = engine; this.Color = color;
    }

    @Override
    void getData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Brand name,Cost,EngineType and Colour");
        Brand = sc.next(); Cost = sc.nextInt(); EngineType = sc.next(); Color = sc.next();
    }

    @Override
    void putData() {
        System.out.println("Brand:" + Brand + "\nCost:" + Cost + "\n EngineType:" +
                           EngineType + "\nColor:" + Color + " \nYear of Manufacture:" + yom +
                           "\nHas helmet:" + hashelmet);
    }
}

final class FourWheeler extends Vehicle {
    public FourWheeler(int n) {
        super(false, n);
    }

    @Override
    void getData() {}

    @Override
    void putData() {
        System.out.println("Year of Manufacture:" + yom + "\nHas helmet:" + hashelmet);
    }
}

class MyTwoWheeler extends TwoWheeler {
    String OwnerName;

    public MyTwoWheeler(String owner, int year, String brand, int cost, String engine, String color) {
        super(year, brand, cost, engine, color);
        this.OwnerName = owner;
    }
    
    void displayOwner() {
        super.getData();
        super.putData();
        System.out.println("Name:" + OwnerName);
    }
}

public class VehicleAbstract {
    public static void main(String[] args) {
        System.out.println("--- TwoWheeler Demo ---");
        TwoWheeler t1 = new TwoWheeler(1995);
        t1.getData();
        t1.putData();

        System.out.println("\n--- MyTwoWheeler Demo ---");
        MyTwoWheeler bike = new MyTwoWheeler("Cherry", 2025, "Ninja", 500000, "4 stroke", "Green");
        bike.displayOwner();

        System.out.println("\n--- FourWheeler Demo ---");
        FourWheeler car = new FourWheeler(2022);
        car.putData();
    }
}
```

## 3. Savings Account
**File:** `SavingsAccountDemo.java`
```java
class SavingsAccount {
    static double annualInterestRate;
    private double savingsBalance;

    public SavingsAccount(double balance) {
        this.savingsBalance = balance;
    }

    public void calculateMonthlyInterest() {
        savingsBalance += (savingsBalance * annualInterestRate) / 12;
    }

    public static void modifyInterestRate(double newRate) {
        annualInterestRate = newRate;
    }

    public void printBalance() {
        System.out.printf("Balance: Rs. %.2f%n", savingsBalance);
    }
}

public class SavingsAccountDemo {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount(2000.00);
        SavingsAccount saver2 = new SavingsAccount(3000.00);

        SavingsAccount.modifyInterestRate(0.04);
        System.out.println(">> Rate: 4%");
        
        saver1.calculateMonthlyInterest();
        System.out.print("Saver 1 "); saver1.printBalance();
        
        saver2.calculateMonthlyInterest();
        System.out.print("Saver 2 "); saver2.printBalance();

        SavingsAccount.modifyInterestRate(0.05);
        System.out.println("\n>> Rate: 5%");
        
        saver1.calculateMonthlyInterest();
        System.out.print("Saver 1 "); saver1.printBalance();
        
        saver2.calculateMonthlyInterest();
        System.out.print("Saver 2 "); saver2.printBalance();
    }
}
```

## 4. Student/Staff Packages
**File:** `CollegeMain.java`
```java
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
```
**File:** `student/Student.java`
```java
package student;
public class Student {
    String usn, dept; int g1, g2, g3;
    public Student(String u, String d, int a, int b, int c) { usn = u; dept = d; g1 = a; g2 = b; g3 = c; }
    public void display() {
        System.out.println("\n--- 🎓 Student: " + usn + " ---");
        System.out.printf("Dept: %s | Grades: %d %d %d | SGPA: %.2f\n", dept, g1, g2, g3, (g1+g2+g3)/30.0);
    }
}
```
**File:** `staff/Staff.java`
```java
package staff;
public class Staff {
    String id, name, desig, sub;
    public Staff(String i, String n, String d, String s) { id = i; name = n; desig = d; sub = s; }
    public void display() {
        System.out.println("\n--- 👩‍🏫 Staff: " + name + " ---");
        System.out.printf("ID: %s | Role: %s | Subject: %s\n", id, desig, sub);
    }
}
```

## 5. Threads
**File:** `ThreadDemo.java`
```java
class PrimeThread extends Thread {
    public void run() {
        try {
            for (int i = 1; i <= 100; i++) {
                if (isPrime(i)) {
                    System.out.println("Prime Thread: " + i);
                    Thread.sleep(500); // Sleep for 0.5 seconds
                }
            }
        } catch (InterruptedException e) {
            System.out.println("Prime Thread interrupted.");
        }
    }

    private boolean isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

class DivisibleThread extends Thread {
    public void run() {
        try {
            for (int i = 100; i <= 200; i++) {
                System.out.println("Divisible Thread: " + i);
                Thread.sleep(500); // Sleep for 0.5 seconds
            }
        } catch (InterruptedException e) {
            System.out.println("Divisible Thread interrupted.");
        }
    }
}

public class ThreadDemo {
    public static void main(String[] args) {
        System.out.println("--- 🧵 Thread Operations 🧵 ---");
        PrimeThread primeT = new PrimeThread();
        DivisibleThread divisibleT = new DivisibleThread();

        primeT.start();
        divisibleT.start();
    }
}
```

## 6. GUI
**File:** `AllTheBest.java`
```java
import java.awt.*;
import java.awt.event.*;

public class AllTheBest extends Frame {

    public AllTheBest() {
        setTitle("All The Best!");
        setSize(400, 200);
        setVisible(true);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    public void paint(Graphics g) {
        Font font = new Font("Serif", Font.BOLD, 24);
        g.setFont(font);

        g.setColor(Color.RED);
        g.drawString("All The Best", 50, 60);

        g.setColor(Color.BLUE);
        g.drawString("All The Best", 50, 90);

        g.setColor(Color.GREEN);
        g.drawString("All The Best", 50, 120);

        g.setColor(Color.ORANGE);
        g.drawString("All The Best", 50, 150);

        g.setColor(Color.MAGENTA);
        g.drawString("All The Best", 50, 180);
    }

    public static void main(String[] args) {
        if (GraphicsEnvironment.isHeadless()) {
            System.out.println("Headless Mode: No GUI available.");
            return;
        }
        new AllTheBest();
    }
}
```

## 7. JDBC
**File:** `JdbcDemo.java`
```java
import java.sql.*;
public class JdbcDemo {
    public static void main(String[] args) {
        System.out.println("--- 🗄️ DB Connect 🗄️ ---");
        try (Connection c = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "pass");
             Statement s = c.createStatement()) {
            s.execute("CREATE TABLE IF NOT EXISTS Stu (id INT, name VARCHAR(20))");
            s.executeUpdate("INSERT INTO Stu VALUES (1, 'Alice')");
            ResultSet rs = s.executeQuery("SELECT * FROM Stu");
            while (rs.next()) System.out.println(rs.getInt(1) + ": " + rs.getString(2));
        } catch (Exception e) {
            System.out.println("DB Error: " + e.getMessage());
        }
    }
}
```

# Viva Questions

## 1. Car Inheritance (Q1)
*   **Basic:** What is the purpose of the `extends` keyword? How do constructors work in inheritance?
*   **Intermediate:** Explain method overriding. How does `super()` in a constructor differ from `super.method()`? Why are different `getSalePrice()` logics applied to `Truck`, `Ford`, and `Sedan`?
*   **Advanced:** Discuss the advantages of using inheritance for a system like an auto shop. How would you add a new car type with a unique discount logic?

## 2. Vehicle Abstract Class (Q2)
*   **Basic:** What is an abstract class? What is an abstract method?
*   **Intermediate:** When would you use an abstract class instead of an interface? What is a `final` class and why would you declare one? How do you demonstrate an error for an abstract class instantiation?
*   **Advanced:** Explain the concept of polymorphism with abstract classes and methods. How do abstract classes and interfaces complement each other?

## 3. Savings Account (Q3)
*   **Basic:** What is a `static` variable? What is a `private` member?
*   **Intermediate:** Explain the difference between `static` and non-`static` methods. Why is `annualInterestRate` static and `savingsBalance` non-static?
*   **Advanced:** Discuss the implications of `static` variables on memory management and concurrency. How would you ensure thread-safety if multiple threads accessed and modified `savingsBalance`?

## 4. Student/Staff Packages (Q4)
*   **Basic:** (Reinforces Package concept) How do you import classes from another package?
*   **Intermediate:** Explain the advantages of organizing code into packages. How does the Java Virtual Machine (JVM) find classes in different packages?
*   **Advanced:** Discuss the role of access modifiers (`public`, `private`, `protected`, `default`) in package visibility and access control. What are naming conventions for packages?

## 5. Threads (Q5)
*   **Basic:** What is a Thread? What is the difference between a process and a thread?
*   **Intermediate:** How do you create threads in Java using the `Thread` class? What is the purpose of `Thread.sleep()`? What is an `InterruptedException`?
*   **Advanced:** Compare and contrast creating threads using `Thread` class vs. `Runnable` interface. Discuss thread lifecycle, synchronization issues, and how to prevent them.

## 6. GUI (Q6)
*   **Basic:** What is AWT? What is the purpose of `Frame` and `Graphics`?
*   **Intermediate:** How do you draw shapes or text on a `Frame`? Explain event handling in AWT (e.g., `WindowAdapter`).
*   **Advanced:** Compare AWT and Swing. Discuss the event delegation model in Java GUI programming.

## 7. JDBC (Q7)
*   **Basic:** What is JDBC? What are the basic steps to connect to a database using JDBC?
*   **Intermediate:** Explain `Connection`, `Statement`, and `ResultSet` interfaces. How do you execute DDL and DML commands using JDBC?
*   **Advanced:** Discuss prepared statements vs. regular statements. How do you handle SQL injection vulnerabilities? Explain transaction management in JDBC.
