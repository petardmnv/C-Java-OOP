package com.company;

public class Potion extends Item implements Equippable, Consumable{
    private int regenerateMana;
    private int regenerateHealth;

    public Potion(String name, int regenerateMana, int regenerateHealth) {
        super(name);
        this.regenerateHealth = regenerateHealth;
        this.regenerateMana = regenerateMana;
    }

    public int getRegenerateMana() {
        return regenerateMana;
    }

    public void setRegenerateMana(int regenerateMana) {
        this.regenerateMana = regenerateMana;
    }

    public int getRegenerateHealth() {
        return regenerateHealth;
    }

    public void setRegenerateHealth(int regenerateHealth) {
        this.regenerateHealth = regenerateHealth;
    }

    @Override
    public void consume(Character target) {
        target.setCurrentHealth(this.regenerateHealth + target.getCurrentHealth());
        if (target.getCharacterClass().equals("Mage")){
            ((Mage)(target)).setMana(this.regenerateMana + ((Mage)(target)).getMana());
        }
    }
}
