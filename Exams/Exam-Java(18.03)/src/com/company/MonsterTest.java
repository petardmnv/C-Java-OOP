package com.company;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class MonsterTest {
    @Test
    void getPower() {
        List<String> a = new ArrayList<>();
        a.add("Evil");
        Monster testDragon = new Monster(10, 20,"Dragon", a);

        List<Hero> party = Arrays.asList(new Hero[]{new Warrior(1, 2, 1, "Barbarian")});
        assertEquals(200, testDragon.getPower(party));

        party = Arrays.asList(new Hero[]{new Warrior(1, 2, 1, "Knight")});
        assertEquals(250, testDragon.getPower(party));
    }
}