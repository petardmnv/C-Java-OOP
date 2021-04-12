package com.company;

import java.util.ArrayList;
import java.util.List;

public abstract class Character {
    private double currentHealth;
    private int maxHealth;
    private int intelligence;
    private int dexterity;
    private Item[] inventory = new Item[10];
    private Equippable[] hotBar = new Equippable[3];

    public Character(double currentHealth, int maxHealth, int intelligence, int dexterity) {
        this.currentHealth = currentHealth;
        this.maxHealth = maxHealth;
        this.intelligence = intelligence;
        this.dexterity = dexterity;
    }

    public Item[] getInventory() {
        return inventory;
    }

    public void setInventory(Item[] inventory) {
        this.inventory = inventory;
    }

    public Equippable[] getHotBar() {
        return hotBar;
    }

    public void setHotBar(Equippable[] hotBar) {
        this.hotBar = hotBar;
    }

    public double getCurrentHealth() {
        return currentHealth;
    }

    public void setCurrentHealth(double currentHealth) {
        this.currentHealth = currentHealth;
    }

    public int getMaxHealth() {
        return maxHealth;
    }

    public void setMaxHealth(int maxHealth) {
        this.maxHealth = maxHealth;
    }

    public int getIntelligence() {
        return intelligence;
    }

    public void setIntelligence(int intelligence) {
        this.intelligence = intelligence;
    }

    public int getDexterity() {
        return dexterity;
    }

    public void setDexterity(int dexterity) {
        this.dexterity = dexterity;
    }

    public void pick(Item newItem) throws Exception {
        boolean isInventoryFull = true;
        for(int i = 0; i < 10; i++) {
            if (this.inventory[i] == null) {
                this.inventory[i] = newItem;
                isInventoryFull = false;
                break;
            }
        }
        if (isInventoryFull){
            throw new Exception("Inventory is full!");
        }
        if (newItem instanceof Equippable){
            for(int i = 0; i < 3; i++) {
                if (this.hotBar[i] == null) {
                    this.hotBar[i] = (Equippable)(newItem);
                    break;
                }
            }
        }
    }

    public void useAt(int index, Character target) throws Exception {
        if (index < 0 || index >= this.hotBar.length) {
            throw new Exception("HotBar has no item on this index!");
        }

        if (this.hotBar[index] != null){
            if (this.hotBar[index] instanceof Usable){
                ((Usable)(this.hotBar[index])).use(this, target);
            }
            else if (this.hotBar[index] instanceof  Consumable){
                ((Consumable)(this.hotBar[index])).consume(this);
            }
        }else {
            throw new Exception("Empty hotBar slot. There is no item here!");
        }
        Item it = (Item) this.hotBar[index];
        for(int i = 0; i < 10; i++) {
            if (this.inventory[i] != null){
                if (this.inventory[i].getName().equals(it.getName())) {
                    this.inventory[i] = null;
                    break;
                }
            }
        }
        this.hotBar[index] = null;
    }

    abstract protected String getCharacterClass();

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Character class : "+ getCharacterClass() + "\n");
        sb.append("Current Health: " + this.currentHealth + "\n");
        return sb.toString();
    }

    public String toString2(){
        StringBuilder sb = new StringBuilder();
        sb.append("Character class: " + this.getCharacterClass() + "\n");
        sb.append("Current Health: " + this.currentHealth + "\n");
        sb.append("Max Health: " + this.maxHealth + "\n");
        sb.append("Current intelligence: " + this.intelligence + "\n");
        sb.append("Current dexterity: " + this.dexterity + "\n");
        sb.append("Inventory: \n");
        for (Item item: this.inventory) {
            if (item != null) {
                sb.append(item.toString());
            }
        }
        sb.append("Hot Bar: \n");
        for (Equippable item: this.hotBar) {
            if (item != null){
                sb.append(item.toString());
            }
        }
        return sb.toString();
    }
}