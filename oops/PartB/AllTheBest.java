import java.awt.*;
import java.awt.event.*;

public class AllTheBest extends Frame {

    public AllTheBest() {
        setTitle("All The Best!");
        setSize(400, 200);
        setVisible(true);

        // Handle window close event
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    public void paint(Graphics g) {
        // Set font
        Font font = new Font("Serif", Font.BOLD, 24);
        g.setFont(font);

        // Display "All The Best" in 5 different colors
        g.setColor(Color.RED);
        g.drawString("All The Best", 50, 60);

        g.setColor(Color.BLUE);
        g.drawString("All The Best", 50, 90);

        g.setColor(Color.GREEN);
        g.drawString("All The Best", 50, 120);

        g.setColor(Color.ORANGE);
        g.drawString("All The Best", 50, 150);

        g.setColor(Color.MAGENTA);
        g.drawString("All The Best", 50, 180);
    }

    public static void main(String[] args) {
        if (GraphicsEnvironment.isHeadless()) {
            System.out.println("Headless Mode: No GUI available.");
            return;
        }
        new AllTheBest();
    }
}