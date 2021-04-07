package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<Item> i = new ArrayList<>();
        List<Equippable> h = new ArrayList<>();
        Scroll c1 = new Scroll("shit in bag", 10);
        Potion p1 = new Potion("shit", 10, 20);
        Note n = new Note("Isaac", "new update is insane!");


        Mage m = new Mage();
        System.out.println(m.toString());
        Archer a = new Archer();
        System.out.println(a.toString());


        System.out.println(m.toString2());
        System.out.println(a.toString2());

        // I have played too much isaac sorry
        Potion p = new Potion("shit", 10, 20);
        p.consume(m);
        p.consume(a);

        System.out.println(m.toString2());
        System.out.println(a.toString2());


        Scroll c = new Scroll("shit in bag", 10);
        c.use(m, a);

        System.out.println(m.toString2());
        System.out.println(a.toString2());

    }
}
