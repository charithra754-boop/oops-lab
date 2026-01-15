package minimal_fun;

import java.util.*;

// Functional Interface for Lambda
interface Greeting {
    void say(String msg);
}

public class Level6_Modern {
    public static void main(String[] args) {
        System.out.println("=== LEVEL 6: MODERN JAVA ===");

        // --- TOPIC 13: Lambda Expressions ---
        // (parameter) -> expression
        Greeting g = (msg) -> System.out.println("Lambda says: " + msg);
        g.say("Hello World!");

        // --- TOPIC 14: Collection Frameworks ---
        System.out.println("\n--- The Inventory (ArrayList) ---");
        ArrayList<String> inventory = new ArrayList<>();
        inventory.add("Sword");
        inventory.add("Shield");
        inventory.add("Potion");
        
        // Iterating
        for(String item : inventory) {
            System.out.println("- " + item);
        }
        
        System.out.println("\n--- The Spellbook (HashMap) ---");
        HashMap<String, Integer> spells = new HashMap<>();
        spells.put("Fireball", 50);
        spells.put("IceShard", 30);
        
        spells.forEach((k, v) -> System.out.println("Spell: " + k + ", Damage: " + v));
    }
}
