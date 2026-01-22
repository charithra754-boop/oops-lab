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