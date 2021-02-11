package com.company;

public class Main {

    public static void main(String[] args) {
	    Point a = new Point(2, 3);
        Point b = new Point(4, 5);
        Point c = new Point(7, 3);

        Point a1 = new Point(10, 3);
        Point b1 = new Point(4, 5);
        Point c1 = new Point(7, 8);
        Triangle t = new Triangle(a, b, c);
        Triangle t1 = new Triangle(a1, b1, c1);

        Triangle[] arr = {t, t1};
        System.out.println(getMaxPerimeter(arr).getArea());
    }
    public static Triangle getMaxPerimeter(Triangle[] arr){
        Triangle r_t = arr[0];
        for (int i = 1; i < arr.length; i++){
            if (r_t.getPerimeter() < arr[i].getPerimeter()){
                r_t = arr[i];
            }
        }
        return r_t;
    }
}
