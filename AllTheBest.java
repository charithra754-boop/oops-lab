import javax.swing.*;
import java.awt.*;

public class AllTheBest {
    public static void main(String[] args) {
        if (GraphicsEnvironment.isHeadless()) { System.out.println("Headless Mode: No GUI."); return; }
        
        JFrame f = new JFrame("Good Luck!");
        f.setLayout(new FlowLayout());
        f.setSize(300, 200);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // RGB colors loop
        Color[] cols = {Color.RED, Color.GREEN, Color.BLUE};
        for (Color c : cols) {
            JLabel l = new JLabel("All The Best! ");
            l.setForeground(c);
            f.add(l);
        }
        
        f.setVisible(true);
        // Fun Fact: 'Hello World' is often the first program, but this is the Best program!
    }
}