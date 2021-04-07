package com.company;

public class Disease {
    private String name;
    private Symptom[] symptoms;

    public Disease(String name, Symptom[] symptoms) {
        this.name = name;
        this.symptoms = symptoms;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Symptom[] getSymptoms() {
        return symptoms;
    }

    public void setSymptoms(Symptom[] symptoms) {
        this.symptoms = symptoms;
    }

}
