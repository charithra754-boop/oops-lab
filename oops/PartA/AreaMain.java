import java.util.Scanner;

public class AreaMain {
    public static void main(String[] args) {
        System.out.println("--- 📐 Shape Calculator 📐 ---");
        // Fun Fact: A hexagon is the most efficient shape for packing (bees know this!).

        Scanner sc = new Scanner(System.in);

        // Quick input handling
        System.out.print("Rect (L W): ");
        Shape rect = new Rectangle(sc.nextDouble(), sc.nextDouble());
        
        System.out.print("Tri (B H): ");
        Shape tri = new Triangle(sc.nextDouble(), sc.nextDouble());

        System.out.println("Rect Area: " + rect.calculateArea());
        System.out.println("Tri Area : " + tri.calculateArea());
        
        sc.close();
    }
}