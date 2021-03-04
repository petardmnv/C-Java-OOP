package com.company;

public class Rectangle implements Figure{
    private Point a;
    private Point b;

    public Rectangle(Point a, Point b) {
        this.a = a;
        this.b = b;
    }

    public Point getA() {
        return a;
    }

    public void setA(Point a) {
        this.a = a;
    }

    public Point getB() {
        return b;
    }

    public void setB(Point b) {
        this.b = b;
    }

    @Override
    public double getArea() {
        double sideOne = this.getSide(a.getX(), a.getY(), a.getX(), b.getY());
        double sideTwo = this.getSide(a.getX(), b.getY(), b.getX(), b.getY());
        return (sideOne * sideTwo) / 2;
    }

    @Override
    public double getPerimeter() {
        double sideOne = this.getSide(a.getX(), a.getY(), a.getX(), b.getY());
        double sideTwo = this.getSide(a.getX(), b.getY(), b.getX(), b.getY());
        return 2 * (sideOne + sideTwo);
    }

    public double getSide(double x1, double y1, double x2, double y2) {
        return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
    }
}
