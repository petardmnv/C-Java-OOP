package com.company;

public class Doctor {
    private String firstName;
    private String lastName;
    private Disease[] diseases;

    public Doctor(String firstName, String lastName, Disease[] diseases) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.diseases = diseases;
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

    public Disease[] getDiseases() {
        return diseases;
    }

    public void setDiseases(Disease[] diseases) {
        this.diseases = diseases;
    }

    public Disease diagnose(Patient client, Symptom[] symptoms) throws Exception{
        /*public Disease diagnose(Patient client, Symptoms[] symptoms)
        Метода приема като параметри клиента и масив с неговите симптоми. Като резултат връща болестта която съответства на симптомите.
        Ако лекаря не знае за болест с такива симптоми, трябва да се хвърли грешка.
        Ако е намерена болест то трябва да се впише в досието на пациента
        */
        int currentIndex = -1;
        for (int i = 0; i < this.diseases.length; i++) {
            if (this.diseases[i].getSymptoms().length == symptoms.length){
                boolean areSymptomsEqual = true;
                for (int j = 0; j < this.diseases[i].getSymptoms().length; j++) {
                    if (this.diseases[i].getSymptoms()[j] != symptoms[j]){
                        areSymptomsEqual = false;
                    }
                }
                if (areSymptomsEqual){
                    currentIndex = i;
                }
            }
        }
        if (currentIndex == -1){
            throw new Exception("Didn't found disease!");
        }

        return this.diseases[currentIndex];
    }
}
