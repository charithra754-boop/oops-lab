public class ThreadDemo {
    public static void main(String[] args) {
        // Fun Fact: Threads are like juggling - multiple balls in the air, one hand processing them!
        new T("Prime", 500).start();
        new T("Divisible", 500).start();
    }
}

class T extends Thread {
    String type; int delay;
    public T(String t, int d) { type = t; delay = d; }
    
    public void run() {
        try {
            for (int i = 1; i <= 10; i++) {
                if (type.equals("Prime") && isPrime(i)) System.out.println("Prime: " + i);
                if (type.equals("Divisible") && i % 6 == 0) System.out.println("Divisible by 6: " + i);
                Thread.sleep(delay);
            }
        } catch (InterruptedException e) {}
    }

    boolean isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
        return true;
    }
}