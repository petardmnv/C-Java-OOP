package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Warrior extends Hero{

    public Warrior(int level, int power, int iq, String spec) {
        super(level, power, iq, spec);
    }

    public double getPower(List<Hero> party, Monster monster){
        double power = this.getLevel() * this.getPower();

        List<String> names = new ArrayList<String>();
        for (Hero hero : party) {
            names.add(hero.getSpec());
        }

        int freq = 0;
        if (this.getSpec().equals("Knight")){
            freq = Collections.frequency(names, "Cleric");
        }

        power = power + power * 0.25 * freq;
        return power;
    }

}
