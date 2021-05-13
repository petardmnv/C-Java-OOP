package com.company;

public class Automobile {
    private String marker;
    private String model;
    private double Multiplayer;

    public Automobile(String marker, String model, double multiplayer) {
        this.marker = marker;
        this.model = model;
        Multiplayer = multiplayer;
    }

    public String getMarker() {
        return marker;
    }

    public void setMarker(String marker) {
        this.marker = marker;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public double getMultiplayer() {
        return Multiplayer;
    }

    public void setMultiplayer(double multiplayer) {
        Multiplayer = multiplayer;
    }
}
