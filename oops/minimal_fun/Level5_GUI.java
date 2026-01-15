package minimal_fun;

import javax.swing.*;
import java.awt.event.*;

// --- TOPIC 12: Swing ---
public class Level5_GUI {
    public static void main(String[] args) {
        // Frame
        JFrame f = new JFrame("Fun Clicker");
        f.setSize(300, 200);
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Components
        JButton b = new JButton("Click Me!");
        b.setBounds(80, 50, 120, 40);
        
        JLabel l = new JLabel("Clicks: 0");
        l.setBounds(110, 100, 100, 20);

        // --- TOPIC 11: Event Handling (Listener Interface) ---
        b.addActionListener(new ActionListener() {
            int count = 0;
            public void actionPerformed(ActionEvent e) {
                count++;
                l.setText("Clicks: " + count);
                System.out.println("Button clicked! Count: " + count);
            }
        });

        // Add & Show
        f.add(b);
        f.add(l);
        // f.setVisible(true); // Uncomment to run in a GUI environment
        
        System.out.println("=== LEVEL 5: GUI created (Headless mode) ===");
        System.out.println("Check the code to see JFrame/JButton logic!");
    }
}
