package com.company;

public class Record {
    private Patient patient;
    private Visit[] visits;

    public Record(Patient patient, Visit[] visits) {
        this.patient = patient;
        this.visits = visits;
    }

    public Patient getPatient() {
        return patient;
    }

    public void setPatient(Patient patient) {
        this.patient = patient;
    }

    public Visit[] getVisits() {
        return visits;
    }

    public void setVisits(Visit[] visits) {
        this.visits = visits;
    }
}
