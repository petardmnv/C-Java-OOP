package com.company;

import java.util.Objects;

public class Item {
    private int id;
    private String name;
    private double price;
    private Unit unit;

    public Item(String name, double price, com.company.Unit unit) {
        this.name = name;
        this.price = price;
        this.unit = unit;
    }

    @Override
    public int hashCode() {
        return Objects.hash(this.name, this.price, this.unit);
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public Unit getUnit() {
        return unit;
    }

    public void setUnit(Unit unit) {
        this.unit = unit;
    }
}
