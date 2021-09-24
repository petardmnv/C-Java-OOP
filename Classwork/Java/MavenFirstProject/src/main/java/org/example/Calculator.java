package org.example;


import java.util.ArrayList;
import java.util.List;

public class Calculator {
    List<Operation> operations = new ArrayList<Operation>();

    public Calculator(List<Operation> operations) {
        this.operations = operations;
    }
}
