package com.company;

public class Circle implements Figure{
    private Point a;
    private double r;

    public Circle(Point a, double r) {
        this.a = a;
        this.r = r;
    }

    public Point getA() {
        return a;
    }

    public void setA(Point a) {
        this.a = a;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }

    @Override
    public double getArea() {
        return 3.14 * r * r;
    }

    @Override
    public double getPerimeter() {
        return 2 * 3.14 * r;
    }
}
