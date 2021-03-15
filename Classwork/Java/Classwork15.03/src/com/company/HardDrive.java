package com.company;

public class HardDrive  implements IPart {
    private double speed;
    private double capacity;


    public HardDrive(double speed, double capacity) {
        this.speed = speed;
        this.capacity = capacity;
    }

    public double getSpeed() {
        return speed;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }

    public double getCapacity() {
        return capacity;
    }

    public void setCapacity(double capacity) {
        this.capacity = capacity;
    }

    @Override
    public PowerData getConsumption() {
        final double typicalPower = this.speed / this.capacity / 160000;
        final double minimalPower = typicalPower * 0.1;
        final double maximalPower = typicalPower * 2;

        return new PowerData(minimalPower, maximalPower, typicalPower);
    }
}