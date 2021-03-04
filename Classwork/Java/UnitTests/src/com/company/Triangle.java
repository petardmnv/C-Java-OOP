package com.company;

public class Triangle implements Figure{
    private Point a;
    private Point b;
    private Point c;

    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
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
    public Point getC() {
        return c;
    }

    public void setC(Point c) {
        this.c = c;
    }

    @Override
    public double getArea() {
        double sideOne = this.getSide(a.getX(), a.getY(), b.getX(), b.getY());
        double sideTwo = this.getSide(a.getX(), a.getY(), c.getX(), c.getY());
        double sideThree = this.getSide(c.getX(), c.getY(), b.getX(), b.getY());
        double halfPerimeter = (sideOne + sideThree + sideTwo) / 2;
        return Math.sqrt(halfPerimeter * (halfPerimeter - sideOne) * (halfPerimeter - sideTwo) * (halfPerimeter - sideThree));
    }

    @Override
    public double getPerimeter() {
        double sideOne = this.getSide(a.getX(), a.getY(), b.getX(), b.getY());
        double sideTwo = this.getSide(a.getX(), a.getY(), c.getX(), c.getY());
        double sideThree = this.getSide(c.getX(), c.getY(), b.getX(), b.getY());
        return sideOne + sideThree + sideTwo;
    }

    public double getSide(double x1, double y1, double x2, double y2) {
        return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
    }
}
