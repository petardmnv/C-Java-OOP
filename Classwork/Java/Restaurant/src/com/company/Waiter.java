package com.company;

public class Waiter extends Thread {
    private String name;

    public Waiter(String name) {
        this.name = name;
    }
}
