public class Rectangle implements Shape {
    double l, w; // Length, Width

    public Rectangle(double l, double w) { this.l = l; this.w = w; }

    @Override
    public double calculateArea() {
        return l * w; // Area = length * width
    }
}