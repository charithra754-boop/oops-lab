import java.util.Scanner;

class Stack {
    int[] stk;
    int top;
    final int SIZE = 10;

    Stack() {
        stk = new int[SIZE];
        top = -1;
    }

    void push(int item) {
        if (top == SIZE - 1) System.out.println("Stack Overflow!");
        else { stk[++top] = item; System.out.println("Pushed: " + item); }
    }

    int pop() {
        if (top == -1) { System.out.println("Stack Underflow!"); return -1; }
        else return stk[top--];
    }

    void display() {
        if (top == -1) { System.out.println("Stack Empty"); return; }
        System.out.print("Stack: ");
        for (int i = 0; i <= top; i++) System.out.print(stk[i] + " ");
        System.out.println();
    }
}

public class StackDemo {
    public static void main(String[] args) {
        Stack s1 = new Stack();
        Stack s2 = new Stack();

        System.out.println(">> Stack 1 Ops:");
        s1.push(10); s1.push(20);
        s1.display();
        System.out.println("Popped: " + s1.pop());

        System.out.println("\n>> Stack 2 Ops:");
        for(int i=1; i<=5; i++) s2.push(i*100);
        s2.display();
    }
}
