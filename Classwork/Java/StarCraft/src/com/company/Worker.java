package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Semaphore;

import static java.lang.Thread.sleep;

public class Worker implements Runnable {
    // Work - collect crystals from crystal mine
    // Workers work alone. They are threads
    Map<Crystal, Integer> usedMines = new HashMap<>();
    private int id;
    private int minedCrystal;
    private Base base;

    public Worker(Base base, int id, int minedCrystal) {
        this.base = base;
        this.id = id;
        this.minedCrystal = minedCrystal;
    }

    public synchronized int getMinedCrystal() {
        return minedCrystal;
    }

    public synchronized void addToMinedCrystal(int minedCrystal) {
        this.minedCrystal += minedCrystal;
    }

    public synchronized int getId() {
        return id;
    }

    @Override
    public void run() {
        // See if mine is empty
        // Mine if not or switch mine
        // if no mines available stop
        while (base.getMinesCount() > 0){
            Crystal mine = goingToMine();
            try{
                while(getMinedCrystal() < 20){
                    if(mine == null){
                        break;
                    }
                    System.out.printf("Miner %d is mining from block %d", id, mine.getMineId());
                    sleep(1500);
                    int neededCrystals = getMinedCrystal();
                    int amount = mine.subtractFromCrystalCount(20 - neededCrystals);
                    addToMinedCrystal(amount);
                    if(amount == 0){
                        base.removeMine(mine);
                        base.removeWorkerToMine(mine);
                        mine = goingToMine();
                    }
                }
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            base.removeWorkerToMine(mine);
            try {
                sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            base.addToResource(minedCrystal);

            try {
                sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }
    }
    public synchronized Crystal goingToMine() {
        int time = 1000;
        Crystal mine = base.getMine();
        if (mine == null) {
            return null;
        }
        try {
            System.out.printf("Worker with id %d is going to mine %d", id, mine.getMineId());
            sleep(time);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        if (!base.addWorkerToMine(mine)) {
            while (true) {
                System.out.printf("Too many miners in the mine. Worker %d going to next mine...", id);
                time = 500;
                try {
                    sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                mine = base.getMine();
                if (mine == null) {
                    return null;
                }
                if (base.addWorkerToMine(mine)) {
                    break;
                }
            }
        }
        return mine;
    }

}
