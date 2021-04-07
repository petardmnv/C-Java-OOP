package com.company;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class WarriorTest {
    Warrior hero = new Warrior(4, 25, 1, "Knight");
    @Test
    void getPower() {
        Hero hero2 = new Warrior(1, 2, 1, "Cleric");
        Hero hero1 = new Warrior(1, 2, 1, "Knight");
        List<Hero> h = new ArrayList<Hero>();
        h.add(hero1);
        h.add(hero2);
        List<String> a = new ArrayList<>();
        a.add("Evil");
        Monster testDragon = new Monster(10, 20,"Dragon", a);
        double power = hero.getPower(h, testDragon);
        Assertions.assertEquals(125, power);
        h.remove(1);
        power = hero.getPower(h, testDragon);
        Assertions.assertEquals(100, power);
    }
}