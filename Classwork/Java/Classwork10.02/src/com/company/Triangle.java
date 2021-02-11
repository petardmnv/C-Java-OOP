package com.company;
import java.lang.Math;

import java.lang.Math;

public class Triangle {

    private Point p1;
    private Point p2;
    private Point p3;

    public Triangle(Point p1, Point p2, Point p3){
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    public double getLine(Point a, Point b){
        double l1 = Math.abs(a.getX() - b.getX());
        double l2 = Math.abs(a.getX() - b.getX());
        return Math.sqrt(Math.pow(l1, 2) + Math.pow(l2, 2));
    }
    public double getPerimeter(){
        double a = getLine(p1, p2);
        double b = getLine(p2, p3);
        double c = getLine(p1, p3);
        return a + b + c;
    }

    public double getArea(){
        double a = getLine(p1, p2);
        double b = getLine(p2, p3);
        double c = getLine(p1, p3);
        double p = getPerimeter();
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }

    public Point getP1() {
        return p1;
    }

    public Point getP2() {
        return p2;
    }

    public Point getP3() {
        return p3;
    }

    public void setP1(Point p1) {
        this.p1 = p1;
    }

    public void setP2(Point p2) {
        this.p2 = p2;
    }

    public void setP3(Point p3) {
        this.p3 = p3;
    }
}
