package com.company;

import java.util.ArrayList;

import static java.lang.Thread.sleep;

public class Race implements Runnable{
    private ArrayList<Automobile> cars = new ArrayList<>();
    private int laps;
    private ArrayList<Double> track = new ArrayList<Double>();

    public Race(ArrayList<Automobile> cars, int laps, ArrayList<Double> track) {
        this.cars = cars;
        this.laps = laps;
        this.track = track;
    }

    public ArrayList<Automobile> getCars() {
        return cars;
    }

    public void setCars(ArrayList<Automobile> cars) {
        this.cars = cars;
    }

    public int getLaps() {
        return laps;
    }

    public void setLaps(int laps) {
        this.laps = laps;
    }

    public ArrayList<Double> getTrack() {
        return track;
    }

    public void setTrack(ArrayList<Double> track) {
        this.track = track;
    }

    public void addCar(Automobile car) {
        this.cars.add(car);
    }

    public void changeTrack(ArrayList<Double> newTrack) {
        this.track = newTrack;
    }

    public void reset() {
        this.cars.clear();
        this.track.clear();
        this.laps = 0;
    }

    public void prepareCars(){
        for(Automobile a: cars){
            a.addTrackSegment(track);
        }
    }


    @Override
    public void run() {
        this.reset();
        prepareCars();
        while(true){
            cars.stream().sorted((c1, c2) -> Double.compare(c1.getInCurrentSegment(), c2.getInCurrentSegment()));
            try{
                sleep(500);
            }catch(Exception e){
                System.out.println(e);
            }
        }

    }
}