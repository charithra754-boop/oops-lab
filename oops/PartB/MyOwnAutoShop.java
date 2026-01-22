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