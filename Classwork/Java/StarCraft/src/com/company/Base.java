package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Base{
    // Create workers and collect resources
    private int resource;
    List<Worker> workers = new ArrayList<>();
    Map<Crystal, Integer> usedMines = new HashMap<>();
    private List<Crystal> crystals = new ArrayList<>();
    public Base(){

    }

    public Base(List<Worker> workers) {
        this.resource = 0;
        this.workers = workers;
    }

    public List<Crystal> getCrystals() {
        return crystals;
    }

    private void setUsedMines(){
        for (Crystal c: crystals){
            usedMines.put(c, 0);
        }
    }

    public synchronized boolean addWorkerToMine(Crystal c){
        int using = usedMines.get(c);
        if(using < 2){
            usedMines.put(c, using + 1);
            return true;
        }
        return false;
    }

    public synchronized Map<Crystal, Integer> getUsedMines() {
        return usedMines;
    }

    public synchronized void removeMine(Crystal c){
        if(crystals.contains(c)) {
            crystals.remove(c);
        }
    }

    public synchronized Crystal getMine(){
        if(crystals.size() == 0){
            return null;
        }
        return crystals.get(0);
    }
    public synchronized  int getMinesCount(){
        return crystals.size();
    }

    public synchronized void removeWorkerToMine(Crystal c){
        int using = usedMines.get(c);
        if(using >= 1){
            usedMines.put(c, using - 1);
        }
    }

    public synchronized void addToResource(int amount){
        this.resource += amount;
    }

    public void addWorker(Worker worker){
        workers.add(worker);
    }

    public void startMining(){
        
    }

}
