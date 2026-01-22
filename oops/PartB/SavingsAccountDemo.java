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