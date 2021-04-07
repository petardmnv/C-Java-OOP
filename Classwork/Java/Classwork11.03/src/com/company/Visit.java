package com.company;

public class Visit {
    private int data;
    private Symptom[] symptoms;
    private Disease disease;

    public Visit(int data, Symptom[] symptoms, Disease disease) {
        this.data = data;
        this.symptoms = symptoms;
        this.disease = disease;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public Symptom[] getSymptoms() {
        return symptoms;
    }

    public void setSymptoms(Symptom[] symptoms) {
        this.symptoms = symptoms;
    }

    public Disease getDisease() {
        return disease;
    }

    public void setDisease(Disease disease) {
        this.disease = disease;
    }
}
