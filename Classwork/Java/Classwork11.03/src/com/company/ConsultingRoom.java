package com.company;

public class ConsultingRoom {
    private Doctor doctor;
    private Record[] patientRecord;

    public ConsultingRoom(Doctor doctor, Record[] patientRecord) {
        this.doctor = doctor;
        this.patientRecord = patientRecord;
    }

    public Doctor getDoctor() {
        return doctor;
    }

    public void setDoctor(Doctor doctor) {
        this.doctor = doctor;
    }

    public Record[] getPatientRecord() {
        return patientRecord;
    }

    public void setPatientRecord(Record[] patientRecord) {
        this.patientRecord = patientRecord;
    }
}
