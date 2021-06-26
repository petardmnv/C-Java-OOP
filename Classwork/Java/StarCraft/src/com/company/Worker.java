package com.company;

import java.util.ArrayList;
import java.util.List;

public class Worker implements Runnable {
    // Work - collect crystals from crystal mine
    // Workers work alone. They are threads
    private List<Crystal> crystals = new ArrayList<>();
    private int id;
    private int mined_crystal;

    public Worker(List<Crystal> crystals, int id, int mined_crystal) {
        this.crystals = crystals;
        this.id = id;
        this.mined_crystal = mined_crystal;
    }

    

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    @Override
    public void run() {

    }
}
