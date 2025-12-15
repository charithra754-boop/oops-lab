import java.util.Scanner;

public class ExceptionDemo {
    public static void main(String[] args) {
        System.out.println("--- 🚫 Error Trapper 🚫 ---");
        // Mnemonic: TRY to do something, CATCH it if it falls, FINALLY clean up the mess!

        try {
            int[] arr = {1, 2, 3};
            System.out.println(arr[new Scanner(System.in).nextInt()]); // May throw exception
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Out of bounds! (Index 0-2 only)");
        } catch (Exception e) {
            System.out.println("Something went wrong: " + e);
        } finally {
            System.out.println("Done.");
        }
    }
}