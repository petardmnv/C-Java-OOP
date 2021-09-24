package com.company;

public class Crystal {
    // This is crystal mine where workers are mining
    private int crystalCount;
    private int mineId;

    public Crystal(int crystalCount, int mineId) {
        this.crystalCount = crystalCount;
        this.mineId = mineId;
    }

    public synchronized int getCrystalCount() {
        return crystalCount;
    }

    public synchronized int getMineId() {
        return mineId;
    }

    public synchronized int subtractFromCrystalCount(int amount){
        if (crystalCount - amount < 0){
            crystalCount = 0;
            return crystalCount;
        }
        crystalCount -= amount;
        return amount;
    }
}
