package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Monster {
    private int level;
    private int power;
    private String name;
    private List<String> traits = new ArrayList<String>();

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<String> getTraits() {
        return traits;
    }

    public void setTraits(List<String> traits) {
        this.traits = traits;
    }

    public Monster(int level, int power, String name, List<String> traits) {
        this.level = level;
        this.power = power;
        this.name = name;
        this.traits = traits;
    }

    public double getPower(List<Hero> party){
        double power = this.level * this.power;

        List<String> names = new ArrayList<String>();
        for (Hero hero : party) {
            names.add(hero.getSpec());
        }

        int freq = 0;
        for (String t: this.traits) {
            if (t.equals("Darkness")){
                freq = freq + Collections.frequency(names, "Cleric");
            }

            if (t.equals("Evil")){
                freq = freq + Collections.frequency(names, "Knight");
                freq = freq + Collections.frequency(names, "Monk");
            }

            if (t.equals("Summoned")){
                freq = freq + Collections.frequency(names, "Barbarian");
            }

            if (t.equals("Holy")){
                freq = freq + Collections.frequency(names, "Warlock");
            }
        }

        power = power + power * 0.25 * freq;
        return power;
    }

}
