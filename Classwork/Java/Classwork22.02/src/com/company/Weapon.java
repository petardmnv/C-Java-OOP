package com.company;

public class Weapon extends Item{
    private String name;
    private int damage;


    public String getName() {
        return name;
    }

    public int getDamage() {
        return damage;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }
}
