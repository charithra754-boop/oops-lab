public class Triangle implements Shape {
    double b, h; // Base, Height

    public Triangle(double b, double h) { this.b = b; this.h = h; }

    @Override
    public double calculateArea() {
        return 0.5 * b * h; // Area = 1/2 * base * height
    }
}