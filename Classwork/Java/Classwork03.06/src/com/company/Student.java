package com.company;

public class Student {
    private String name;
    private int id;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public void solveTask(Problem task){
        if (task.getDifficulty() == Difficulty.LOW){
        }
        if (task.getDifficulty() == Difficulty.MEDIUM){
        }
        if (task.getDifficulty() == Difficulty.HIGH){
        }
    }

}
