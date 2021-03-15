package com.company;

public class Processor implements IPart{
    private int coreCount;
    private double coreFrequency;

    public Processor(int coreCount, double coreFrequency) {
        this.coreCount = coreCount;
        this.coreFrequency = coreFrequency;
    }

    public int getCoreCount() {
        return coreCount;
    }

    public void setCoreCount(int coreCount) {
        this.coreCount = coreCount;
    }

    public double getCoreFrequency() {
        return coreFrequency;
    }

    public void setCoreFrequency(double coreFrequency) {
        this.coreFrequency = coreFrequency;
    }

    @Override
    public PowerData getConsumption() {
        final double typicalPower = this.coreCount * Math.pow(this.coreFrequency, 2)/ 2 * 0.5;
        final double minimalPower = typicalPower * 0.25;
        final double maximalPower = typicalPower * 5;

        return new PowerData(minimalPower, maximalPower, typicalPower);
    }
}
