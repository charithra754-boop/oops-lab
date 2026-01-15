package minimal_fun;

import minimal_fun.mypack.SecretWeapon; // --- TOPIC 6: Packages ---

// --- TOPIC 5: Interface ---
interface Flyer {
    void fly();
}

// --- TOPIC 6: Abstract Class ---
abstract class SuperSuit {
    abstract void powerUp(); // Must be implemented
    void suitUp() {
        System.out.println("Putting on the suit...");
    }
}

// --- TOPIC 5: Inheritance ---
class IronMan extends SuperSuit implements Flyer {
    
    // --- TOPIC 3: Overriding ---
    @Override
    void powerUp() {
        System.out.println("Reactor Online. Sensors Online.");
    }

    @Override
    public void fly() {
        System.out.println("Thrusters engaged! Flying high.");
    }

    // --- TOPIC 3: Overloading ---
    void attack() {
        System.out.println("Punch!");
    }
    
    void attack(String weapon) {
        System.out.println("Firing " + weapon + "!");
    }
}

class Hulk extends SuperSuit {
    @Override
    void powerUp() {
        System.out.println("HULK SMASH MODE!");
    }
}

public class Level2_OOP {
    public static void main(String[] args) {
        System.out.println("=== LEVEL 2: OOP CONCEPTS ===");
        
        // --- TOPIC 3: Dynamic Method Dispatch ---
        // Reference is Abstract Class, Object is Child
        SuperSuit hero1 = new IronMan(); 
        SuperSuit hero2 = new Hulk();
        
        hero1.suitUp();
        hero1.powerUp(); // Calls IronMan's version
        
        hero2.suitUp();
        hero2.powerUp(); // Calls Hulk's version
        
        // Specific capabilities
        IronMan tony = (IronMan) hero1;
        tony.fly();
        tony.attack();
        tony.attack("Unibeam"); // Overloaded

        // Using the package class
        SecretWeapon sw = new SecretWeapon();
        sw.activate();
    }
}
