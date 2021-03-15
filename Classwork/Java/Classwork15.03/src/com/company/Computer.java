package com.company;

import java.util.ArrayList;
import java.util.List;

public class Computer{
    private List<IPart> parts = new ArrayList<IPart>() ;

    public Computer(List<IPart> parts) {
        this.parts = parts;
    }

    public List<IPart> getParts() {
        return parts;
    }

    public void setParts(List<IPart> parts) {
        this.parts = parts;
    }

    public PowerData getConsumption() {
        PowerData powerData = new PowerData(0, 0, 0);
        for (IPart part : this.parts) {
            powerData = powerData.getAllData(part.getConsumption());
        }
        return powerData;
    }
}
