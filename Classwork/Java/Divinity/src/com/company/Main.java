package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        // I have played too much isaac sorry
        Scroll c1 = new Scroll("shit in bag", 10);
        Potion p1 = new Potion("shit", 10, 20);
        Scroll c2 = new Scroll("corn fly", 15);
        Potion p2 = new Potion("holy mantle", 15, 15);
        Scroll c3 = new Scroll("poopyla", 20);
        Potion p3 = new Potion("rage", 20, 25);
        Note n1 = new Note("Isaac", "new");
        Note n2 = new Note("Isaac", "new update");
        Note n3 = new Note("Isaac", "new update is");
        Note n4 = new Note("Isaac", "new update is insane");
        Note n5 = new Note("Isaac", "new update is insane!");
        Note n6 = new Note("Isaac", "new update is insane! Yezzzz");
        DumbBomb mb = new DumbBomb("Suzanita", 3);

        Mage m = new Mage();
        Archer a = new Archer();

        System.out.println(m.toString2());
        System.out.println(a.toString2());

        try {
            m.pick(c1);
            m.pick(c2);
            m.pick(c3);
            m.pick(p1);
            m.pick(p2);
            m.pick(p3);
            m.pick(n1);
            m.pick(n2);
            m.pick(n3);
            m.pick(n4);
            m.pick(n5);
        }catch (Exception e){
            System.out.println(e);
        }

        try{
            a.pick(c3);
            a.pick(mb);
            a.pick(p1);
            a.pick(p3);
            a.pick(n1);
            a.pick(n2);
            a.pick(n3);
        }catch (Exception e){
            System.out.println(e);
        }

        try {
            a.useAt(0, m);
            a.useAt(1, m);
            a.useAt(2, m);
            m.useAt(0, a);
            m.useAt(3, a);
        }catch (Exception e){
            System.out.println(e);
        }

        System.out.println("<-------------------->");
        System.out.println(m.toString2());
        System.out.println(a.toString2());

        System.out.println(m.toString());
        System.out.println(a.toString());

    }
}
