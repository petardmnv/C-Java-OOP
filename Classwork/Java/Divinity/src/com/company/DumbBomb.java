package com.company;

public class DumbBomb extends Item implements Equippable, Usable{
    private int decreaseIntelligence;

    public DumbBomb(String name, int decreaseIntelligence) {
        super(name);
        this.decreaseIntelligence = decreaseIntelligence;
    }

    public int getDecreaseIntelligence() {
        return decreaseIntelligence;
    }

    public void setDecreaseIntelligence(int decreaseIntelligence) {
        this.decreaseIntelligence = decreaseIntelligence;
    }

    @Override
    public void use(Character source, Character target) {
        int newIntelligence = 0;
        // If target is smarter than source => newIntelligence + 1
        if (target.getIntelligence() > source.getIntelligence()){
            newIntelligence = 1;
        }
        newIntelligence += target.getIntelligence() - this.decreaseIntelligence;
        if (newIntelligence < 0){
            newIntelligence = 0;
        }
        target.setIntelligence(newIntelligence);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("DumbBomb name: " + this.getName() + "\n");
        sb.append("     Intelligence Damage: " + this.decreaseIntelligence + "\n");
        return sb.toString();
    }

}