package com.company;

import java.util.ArrayList;
import java.util.List;

public abstract class Character {
    private double currentHealth;
    private int maxHealth;
    private int intelligence;
    private int dexterity;
    private List<Item> inventory = new ArrayList<>();
    private List<Equippable> hotBar = new ArrayList<>();

    public Character(double currentHealth, int maxHealth, int intelligence, int dexterity) {
        this.currentHealth = currentHealth;
        this.maxHealth = maxHealth;
        this.intelligence = intelligence;
        this.dexterity = dexterity;
    }

    public List<Item> getInventory() {
        return inventory;
    }

    public void setInventory(List<Item> inventory) {
        this.inventory = inventory;
    }

    public List<Equippable> getHotBar() {
        return hotBar;
    }

    public void setHotBar(List<Equippable> hotBar) {
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
        if (this.inventory.size() < 10){
            this.inventory.add(newItem);
            if (newItem instanceof Equippable){
                if (this.hotBar.size() < 3){
                    this.hotBar.add((Equippable)(newItem));
                }
            }
        }
        else{
            throw new Exception("Inventory is full!");
        }
    }

    public void useAt(int index, Character target) throws Exception {
        try {
            this.hotBar.get(index);
        } catch (IndexOutOfBoundsException e) {
            throw new Exception("HotBar has no item on this index!");
        }

        if (this.hotBar.get(index) instanceof Usable){
            ((Usable)(this.hotBar.get(index))).use(this, target);
        }
        else if (this.hotBar.get(index) instanceof  Consumable){
            ((Consumable)(this.hotBar.get(index))).consume(this);
        }
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
            sb.append(item.toString());
        }
        sb.append("Hot Bar: \n");
        for (Equippable item: this.hotBar) {
            sb.append(item.toString());
        }
        return sb.toString();
    }
}
//Напишете:
//        - клас Character (представляващ героите в играта) с полета за:
//        - current health (int)
//        - max health (int)
//        - intelligence (int) - skill, определящ ефективността на магиите на героя
//        - dextirity (int) - skill, определящ ефективността на използваните арбалети и лъкове

//- с метод abstract protected String getCharacterClass(), който връща името на класа на героя (примерно: Mage / Archer)
//        - с имплементация на public String toString(), която връща класа на героя и текущата му кръв