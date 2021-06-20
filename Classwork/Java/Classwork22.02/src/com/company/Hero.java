package com.company;

import java.util.ArrayList;

public class Hero {
    private String name;
    private String hero_class;
    private Equipment equip;
    private Item[] bag;

    public Hero(String name, String hero_class, Equipment equip, Item[] bag) {
        this.name = name;
        this.hero_class = hero_class;
        this.equip = equip;
        this.bag = bag;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getHero_class() {
        return hero_class;
    }

    public void setHero_class(String hero_class) {
        this.hero_class = hero_class;
    }

    public Equipment getEquip() {
        return equip;
    }

    public void setEquip(Equipment equip) {
        this.equip = equip;
    }

    public Item[] getBag() {
        return bag;
    }

    public void setBag(Item[] bag) {
        this.bag = bag;
    }
    public void pickUpItem(Item item) throws Exception {
        //check if bag is full
        if (this.bag.length >= 6){
            throw new Exception("Bag is full!");
        }
    }
}
