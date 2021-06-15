package com.company;

public class Problem {
    static int id = 0;
    private int number;
    private int points;
    private Enum<Difficulty> difficulty;

    public Problem(int points, Enum<Difficulty> difficulty) {
        this.number = ++id;
        this.points = points;
        this.difficulty = difficulty;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public int getPoints() {
        return points;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    public Enum<Difficulty> getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(Enum<Difficulty> difficulty) {
        this.difficulty = difficulty;
    }
}
