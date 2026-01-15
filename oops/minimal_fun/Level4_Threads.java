package minimal_fun;

// --- TOPIC 9: Multi-threading (Extending Thread) ---
class Racer extends Thread {
    String name;
    Racer(String name) { this.name = name; }
    
    public void run() {
        for(int i=1; i<=3; i++) {
            System.out.println(name + " is at checkpoint " + i);
            try { Thread.sleep(100); } catch (Exception e) {}
        }
        System.out.println(name + " finished!");
    }
}

// --- TOPIC 10: Synchronization ---
class BankAccount {
    private int balance = 100;
    
    // Only one thread can withdraw at a time!
    synchronized void withdraw(int amount) {
        if (balance >= amount) {
            System.out.println(Thread.currentThread().getName() + " is withdrawing " + amount);
            balance -= amount;
            System.out.println("Remaining: " + balance);
        } else {
            System.out.println(Thread.currentThread().getName() + " tried to withdraw, but Insufficient Funds!");
        }
    }
}

public class Level4_Threads {
    public static void main(String[] args) {
        System.out.println("=== LEVEL 4: THREADS ===");
        
        // Race
        Racer r1 = new Racer("Ferrari");
        Racer r2 = new Racer("Lamborghini");
        r1.start();
        r2.start();
        
        try { r1.join(); r2.join(); } catch(Exception e) {} // Wait for race to end
        
        System.out.println("\n--- Sync Demo (The ATM) ---");
        BankAccount atm = new BankAccount();
        
        Runnable task = () -> atm.withdraw(80);
        
        Thread t1 = new Thread(task, "Husband");
        Thread t2 = new Thread(task, "Wife");
        
        t1.start();
        t2.start();
    }
}
