package com.company;

public class Crystal {
    // This is crystal mine where workers are mining

    private int crystal_count;

    public Crystal(int crystal_count) {
        this.crystal_count = crystal_count;
    }
    public synchronized  int getCrystal_count() {
        return crystal_count;
    }

    public synchronized void setCrystal_count(int crystal_count) {
        this.crystal_count = crystal_count;
    }

}
