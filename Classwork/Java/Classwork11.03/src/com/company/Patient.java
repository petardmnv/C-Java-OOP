package com.company;

public class Patient {
    private String firstName;
    private String lastName;
    private int EGN;

    public Patient(String firstName, String lastName, int EGN) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.EGN = EGN;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public int getEGN() {
        return EGN;
    }

    public void setEGN(int EGN) {
        this.EGN = EGN;
    }
}
