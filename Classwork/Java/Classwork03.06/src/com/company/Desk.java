package com.company;

import java.util.Comparator;
import java.util.List;

public class Desk {
    private List<Problem> problems;

    public List<Problem> getProblems() {
        return problems;
    }

    public void setProblems(List<Problem> problems) {
        this.problems = problems;
    }

    public Problem getNextConsistentTask(int previousTaskNumber) throws Exception{
        if (previousTaskNumber < 0){
            throw new Exception("Number is negative!");
        }
        if (previousTaskNumber >= problems.size()){
            throw new Exception("Index out of bound!");
        }
        for (Problem p : problems) {
            if (p.getNumber() == previousTaskNumber + 1) {
                return p;
            }
        }
    }

    public Problem getNextSmartTask(int previousTaskNumber) throws Exception{
        if (previousTaskNumber < 0){
            throw new Exception("Number is negative!");
        }
        if (previousTaskNumber > problems.size()){
            throw new Exception("Index out of bound!");
        }
        problems.sort((o1, o2) -> o1.getPoints() - o2.getPoints());

        for (int i = 0; i < problems.size() - 1; i++) {
            if (problems.get(i).getNumber() == previousTaskNumber){
                if (previousTaskNumber == 0){
                    return problems.get(i);
                }
                return problems.get(i + 1);
            }
        }
    }
}


