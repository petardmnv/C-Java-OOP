package com.company;

public abstract class Item {
    private String name;

    public Item(String name) {
        this.name = name;
    }

    public abstract String toString();

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
