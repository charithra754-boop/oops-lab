import AdvMath.*;
import java.util.Scanner;

public class MathMain {
    public static void main(String[] args) {
        System.out.print("--- 🧮 Math Wiz --- \nEnter Angle (deg): ");
        // Fun Fact: Zero is the only number that can't be represented in Roman numerals.
        
        Scanner sc = new Scanner(System.in);
        double rad = new AngleConverter().toRad(sc.nextDouble());
        System.out.printf("Result (sin+cos+tan): %.4f\n", new TrigAlgo().complexTrig(rad));
        sc.close();
    }
}