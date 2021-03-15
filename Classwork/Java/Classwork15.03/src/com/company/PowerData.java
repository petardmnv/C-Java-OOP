package com.company;

public class PowerData{
    public final double minimalPower;
    public final double maximalPower;
    public final double typicalPower;

    public double getMinimalPower() {
        return minimalPower;
    }

    public double getMaximalPower() {
        return maximalPower;
    }

    public double getTypicalPower() {
        return typicalPower;
    }

    public PowerData getAllData(PowerData powerdata){
        return new PowerData(this.maximalPower + powerdata.minimalPower, this.maximalPower + powerdata.maximalPower, this.typicalPower + powerdata.typicalPower);
    }

    public PowerData(double minimalPower, double maximalPower, double typicalPower) {
        this.minimalPower = minimalPower;
        this.maximalPower = maximalPower;
        this.typicalPower = typicalPower;

    }
}
