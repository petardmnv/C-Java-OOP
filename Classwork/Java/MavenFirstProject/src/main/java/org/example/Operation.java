package org.example;

import java.util.ArrayList;
import java.util.List;

class Operation {
    private String operatingSymbol;
    private List<Double> numbers = new ArrayList<Double>();

    public Operation(String operation, List<Double> numbers) {
        this.operatingSymbol = operation;
        this.numbers = numbers;
    }

    public List<Double> getNumbers() {
        return numbers;
    }

    public void setNumbers(List<Double> numbers) {
        this.numbers = numbers;
    }

    public String getOperatingSymbol() {
        return operatingSymbol;
    }

    public void setOperatingSymbol(String operatingSymbol) {
        this.operatingSymbol = operatingSymbol;
    }

    public double performOperation() throws Exception {
        double result = 0;
        if (numbers.size() == 1){
            return numbers.get(0);
        }
        switch(operatingSymbol.toLowerCase()){
            case "add":
                result = numbers.stream().mapToDouble(f -> f).sum();
                break;
            case "mul":
                double tmpResult = numbers.get(0);
                for (int i = 1; i < numbers.size(); i++){
                    tmpResult *= numbers.get(i);
                }
                result = tmpResult;
                break;
            case "div":
                tmpResult = numbers.get(0);
                for (int i = 1; i < numbers.size(); i++){
                    tmpResult /= numbers.get(i);
                }
                result = tmpResult;
                break;
            case "sub":
                tmpResult = numbers.get(0);
                for (int i = 1; i < numbers.size(); i++){
                    tmpResult -= numbers.get(i);
                }
                result = tmpResult;
                break;
            default:
                throw new Exception("Invalid command");
        }
        return result;
    }
}
