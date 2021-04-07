package com.company;

public class Mage extends Character{
    private int mana;

    public Mage() {
        super(60, 60, 10, 5);
        this.mana = 80;
    }

    public int getMana() {
        return mana;
    }

    public void setMana(int mana) {
        this.mana = mana;
    }

    @Override
    protected String getCharacterClass() {
        return "Mage";
    }
}
