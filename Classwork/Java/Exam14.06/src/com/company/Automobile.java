package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

import static java.lang.Thread.sleep;

public class Automobile implements Runnable{
    private int position = 1;
    private String name;
    private int lapCount;
    private int inCurrentSegment = 0;
    private List<Double> lapSegments = new ArrayList<>();
    private List<Double> trackSegments = new ArrayList<>();
    private List<Double> timeFromLaps = new ArrayList<>();

    public Automobile(int position, String name, int lapCount, int lapSegments) {
        this.position = position;
        this.name = name;
        this.lapCount = lapCount;
        for(int i = 0; i < lapSegments; i++) {
            this.lapSegments.add(0.0);
        }
    }

    public Automobile(String name, int lapCount, int lapSegments) {
        this.name = name;
        this.lapCount = lapCount;
        for(int i = 0; i < lapSegments; i++) {
            this.lapSegments.add(0.0);
        }
    }

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getLapCount() {
        return lapCount;
    }

    public void setLapCount(int lapCount) {
        this.lapCount = lapCount;
    }

    public List<Double> getLapSegments() {
        return lapSegments;
    }

    public void setLapSegments(List<Double> lapSegments) {
        this.lapSegments = lapSegments;
    }

    public List<Double> getTimeFromLaps() {
        return timeFromLaps;
    }

    public void setTimeFromLaps(List<Double> timeFromLaps) {
        this.timeFromLaps = timeFromLaps;
    }

    public void updateTimeFromLapsByIndex(int index, double amount){
        this.timeFromLaps.add(index, timeFromLaps.get(index) + amount);
    }

    public synchronized void addTrackSegment(ArrayList<Double> currentTrackSegment){
        this.trackSegments = currentTrackSegment;
    }

    public void resetLapSegment(){
        for(int i = 0; i < lapSegments.size(); i++) {
            this.lapSegments.set(i, 0.0);
        }
    }
    public int getInCurrentSegment(){
        return inCurrentSegment;
    }

    @Override
    public void run() {
        for (Double segment: trackSegments) {
            double coef = ThreadLocalRandom.current().nextDouble(0.75, 1.75);
            double currentTime = 1 / segment * coef;
            inCurrentSegment = trackSegments.indexOf(segment);
            lapSegments.set(trackSegments.indexOf(segment), currentTime);
            if (inCurrentSegment == trackSegments.size()){
                timeFromLaps.add(lapSegments.stream()
                        .mapToDouble(a -> a)
                        .sum()
                );
                resetLapSegment();
            }
            try{
                sleep(1000);
            }catch(Exception e){
                System.out.println(e);
            }

        }

    }
}
