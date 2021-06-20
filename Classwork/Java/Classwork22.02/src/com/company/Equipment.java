package com.company;

public class Equipment {
    private Weapon[] weapons;
    private Armour[] armour;
    private Potion[] potion;

    public Equipment(Weapon[] weapons, Armour[] armour, Potion[] potion) {
        this.weapons = weapons;
        this.armour = armour;
        this.potion = potion;
    }

    public Weapon[] getWeapons() {
        return weapons;
    }

    public void setWeapons(Weapon[] weapons) {
        this.weapons = weapons;
    }

    public Armour[] getArmour() {
        return armour;
    }

    public void setArmour(Armour[] armour) {
        this.armour = armour;
    }

    public Potion[] getPotion() {
        return potion;
    }

    public void setPotion(Potion[] potion) {
        this.potion = potion;
    }
}
