package com.company;

import java.util.List;

public class Hero {
    private int level;
    private int power;
    private int iq;
    private String spec;

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    public int getIq() {
        return iq;
    }

    public void setIq(int iq) {
        this.iq = iq;
    }

    public String getSpec() {
        return spec;
    }

    public void setSpec(String spec) {
        this.spec = spec;
    }

    public Hero(int level, int power, int iq, String spec) {
        this.level = level;
        this.power = power;
        this.iq = iq;
        this.spec = spec;
    }
}
