package staff;

public class Staff {
    String id, name, desig, sub;

    public Staff(String i, String n, String d, String s) {
        id = i; name = n; desig = d; sub = s;
    }

    public void display() {
        System.out.println("\n--- 👩‍🏫 Staff: " + name + " ---");
        // Mnemonic: Staff support the structure (like a staff/pole supports a flag!).
        System.out.printf("ID: %s | Role: %s | Subject: %s\n", id, desig, sub);
    }
}