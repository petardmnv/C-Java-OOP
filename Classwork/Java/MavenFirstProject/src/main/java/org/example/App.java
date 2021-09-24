package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class App {
    public static void main( String[] args ){
        Scanner scanner = new Scanner(System.in);
        while(true){
            List<String> line = Arrays.asList(scanner.nextLine().split(" "));;
            String command = line.get(0);
            if (command.equals("exit")){
                break;
            }
            List<Double> numbers = new ArrayList<Double>();
            for (int i = 1; i < line.size(); i ++){
                numbers.add(Double.parseDouble(line.get(i)));
            }
            Operation op = new Operation(command, numbers);
            try {
                System.out.println(op.performOperation());
            }catch(Exception e){
                System.out.println(e);
            }
        }
    }
}
