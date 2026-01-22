import java.util.Scanner;

abstract class Vehicle {
    boolean hashelmet;
    int yom; // year of manufacture

    abstract void getData();
    abstract void putData();

    // Overloaded constructors as per manual
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
    int Cost; // Manual's example uses int for cost
    String EngineType;
    String Color;

    public TwoWheeler(int n) { // Constructor matching manual's example for TwoWheeler(int n)
        super(true, n); // 2-wheeler needs helmet
        // Default values for other fields, to be set by getData()
        this.Brand = "";
        this.Cost = 0;
        this.EngineType = "";
        this.Color = "";
    }

    // Constructor with all fields for MyTwoWheeler super call
    public TwoWheeler(int year, String brand, int cost, String engine, String color) {
        super(true, year);
        this.Brand = brand;
        this.Cost = cost;
        this.EngineType = engine;
        this.Color = color;
    }

    @Override
    void getData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Brand name,Cost,EngineType and Colour");
        Brand = sc.next();
        Cost = sc.nextInt();
        EngineType = sc.next();
        Color = sc.next();
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
        super(false, n); // FourWheeler does not have helmet, use overloaded constructor
    }

    @Override
    void getData() {
        // No specific data for FourWheeler to get in the manual's example
    }

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
    
    void displayOwner() { // Manual has a display() method here that calls super.getData(), putData()
        super.getData(); // Call super's method to get data (as per manual's example)
        super.putData();
        System.out.println("Name:" + OwnerName); // Display owner name
    }
}

public class VehicleAbstract {
    public static void main(String[] args) {
        // Demonstrate error when creating object of Vehicle
        // Vehicle v = new Vehicle(2020); // ERROR: Vehicle is abstract; cannot be instantiated

        // Demonstrate error inheriting from FourWheeler
        // class FiveWheeler extends FourWheeler {} // ERROR: Cannot inherit from final 'FourWheeler'

        System.out.println("--- TwoWheeler Demo ---");
        TwoWheeler t1 = new TwoWheeler(1995); // Example from manual
        t1.getData(); // Get data from user
        t1.putData(); // Display data

        System.out.println("\n--- MyTwoWheeler Demo ---");
        MyTwoWheeler bike = new MyTwoWheeler("Cherry", 2025, "Ninja", 500000, "4 stroke", "Green");
        bike.displayOwner(); // This will call getData() within displayOwner()

        System.out.println("\n--- FourWheeler Demo ---");
        FourWheeler car = new FourWheeler(2022);
        car.putData();
    }
}