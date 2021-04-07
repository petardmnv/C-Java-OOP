package com.company;

public class Scroll extends Item implements Equippable, Usable{
    private int damage;

    public Scroll(String name, int damage) {
        super(name);
        this.damage = damage;
    }

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

    @Override
    public void use(Character source, Character target) {
        int intelligenceGradation = source.getIntelligence() - target.getIntelligence();
        double finalDamage = this.damage + this.damage * 0.1 * intelligenceGradation;
        if (finalDamage < 0){
            finalDamage = 0;
        }
        target.setCurrentHealth(target.getCurrentHealth() - finalDamage);
    }
}
