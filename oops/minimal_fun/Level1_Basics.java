package minimal_fun;

// --- TOPIC 2: Classes & Objects ---
class Hero {
    // --- TOPIC 1: Primitives ---
    String name;
    int powerLevel;
    double health;
    
    // --- TOPIC 2: Static Variable (Shared by all) ---
    static String guildName = "Avengers_Lite";

    // --- TOPIC 4: Constructors ---
    // Default
    Hero() {
        this.name = "Unknown";
        this.powerLevel = 0;
        System.out.println("Spawned a generic NPC.");
    }

    // Parameterized
    Hero(String name, int power) {
        this.name = name;
        this.powerLevel = power;
        this.health = 100.0;
        System.out.println("Hero " + name + " has joined the server!");
    }

    void showStats() {
        // --- TOPIC 1: Operators (Arithmetic & String concat) ---
        double halfHealth = health / 2; 
        System.out.println(name + " [HP: " + health + " | Power: " + powerLevel + "] Guild: " + guildName);
        System.out.println("Warning: Half HP is " + halfHealth);
    }
}

public class Level1_Basics {
    public static void main(String[] args) {
        System.out.println("=== LEVEL 1: BASICS ===");
        
        // Objects
        Hero h1 = new Hero("IronCoder", 9000);
        Hero h2 = new Hero();
        
        h1.showStats();
        
        // Static access
        Hero.guildName = "Justice_League_Beta";
        System.out.println("\nGuild name changed globally!");
        
        h1.showStats(); 
        // h2 also sees the change because it's static
    }
}
