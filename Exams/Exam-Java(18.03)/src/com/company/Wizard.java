package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Wizard extends Hero{

    public Wizard(int level, int power, int iq, String spec) {
        super(level, power, iq, spec);
    }

    public double getPower(List<Hero> party, Monster monster){
        double power = this.getLevel() * this.getIq();

        if (this.getSpec().equals("Cleric")){
            if (monster.getTraits().contains("Darkness") || monster.getTraits().contains("Evil")){
                power = power + power * 0.25;
            }
        }

        if (this.getSpec().equals("Sorcerer")) {
            if (monster.getTraits().contains("Summoned") || monster.getTraits().contains("Evil")) {
                power = power + power * 0.25;
            }
        }

        if (this.getSpec().equals("Warlock")){
            if (monster.getTraits().contains("Holy")){
                power = power + power * 0.25;
            }
        }

        return power;
    }
}
