import java.sql.*;

public class JdbcDemo {
    public static void main(String[] args) {
        System.out.println("--- 🗄️ DB Connect 🗄️ ---");
        // Steps: Load -> Connect -> Execute -> Process -> Close
        
        try (Connection c = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "root", "pass");
             Statement s = c.createStatement()) {
             
            s.execute("CREATE TABLE IF NOT EXISTS Stu (id INT, name VARCHAR(20))");
            s.executeUpdate("INSERT INTO Stu VALUES (1, 'Alice')");
            
            ResultSet rs = s.executeQuery("SELECT * FROM Stu");
            while (rs.next()) System.out.println(rs.getInt(1) + ": " + rs.getString(2));

        } catch (Exception e) {
            System.out.println("DB Error (Check Driver/Server): " + e.getMessage());
        }
    }
}