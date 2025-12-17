public class CarProgram {
    public static void main(String[] args) {
        System.out.println("--- 🚗 Car Dealership System (Inheritance Demo) 🚗 ---");
        // Fun Fact: The first speeding ticket was issued in 1902 for driving at 45 mph (scandalous!).

        Car sedan = new Car(100, 20000, "Red");
        Truck ford = new Truck(80, 50000, "Blue", 3000); // Heavy truck -> 10% discount
        Truck miniTruck = new Truck(90, 30000, "White", 1500); // Light truck -> 20% discount

        System.out.println("Sedan Price: $" + sedan.getSalePrice());
        System.out.println("Heavy Truck Price: $" + ford.getSalePrice());
        System.out.println("Mini Truck Price: $" + miniTruck.getSalePrice());
    }
}

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
        // Logic: Heavier trucks (>2000) get 10% off, lighter ones get 20% off.
        // Mnemonic: Heavy load? Heavy price (less discount).
        return super.getSalePrice() * (weight > 2000 ? 0.90 : 0.80);
    }
}