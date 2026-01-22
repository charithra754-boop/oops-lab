package MyPack;

public class BankCustomer {
    String name;
    double bal;

    public BankCustomer(String n, double b) { name = n; bal = b; }

    public void display() {
        System.out.println("\n--- 🏦 Account: " + name + " 🏦 ---");
        // Fun Fact: Compound interest is often called the 8th wonder of the world!
        System.out.printf("Balance: $%.2f (%s)\n", bal, bal > 1000 ? "Rich!" : "Saving...");
    }
}