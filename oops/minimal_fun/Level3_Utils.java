package minimal_fun;

public class Level3_Utils {
    public static void main(String[] args) {
        System.out.println("=== LEVEL 3: STRINGS & EXCEPTIONS ===");

        // --- TOPIC 7: String Handling ---
        String spell = "   Expelliarmus   ";
        System.out.println("Original: '" + spell + "'");
        System.out.println("Trimmed: '" + spell.trim() + "'");
        System.out.println("Uppercase: " + spell.toUpperCase());
        System.out.println("Contains 'arm': " + spell.contains("arm"));
        System.out.println("Substring: " + spell.trim().substring(0, 7));

        // --- TOPIC 8: Exception Handling ---
        System.out.println("\n--- Casting Spells (Risky Business) ---");
        try {
            int magicPower = 100;
            int resistance = 0; // Uh oh
            int damage = magicPower / resistance; // Divide by zero!
            System.out.println("Damage dealt: " + damage);
        } catch (ArithmeticException e) {
            System.out.println("CRITICAL FAILURE: Cannot divide by zero! (" + e.getMessage() + ")");
        } catch (Exception e) {
            System.out.println("Unknown magical error.");
        } finally {
            System.out.println("Spell cooldown active (Finally block executed).");
        }
    }
}
