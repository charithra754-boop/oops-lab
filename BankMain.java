import MyPack.BankCustomer;
import java.util.Scanner;

public class BankMain {
    public static void main(String[] args) {
        System.out.println("--- Bank System ---");
        Scanner sc = new Scanner(System.in);

        System.out.print("Name & Balance: ");
        // One-liner object creation & usage
        new BankCustomer(sc.next(), sc.nextDouble()).display();
        
        sc.close();
    }
}