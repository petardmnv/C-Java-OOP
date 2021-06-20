import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        List<String> crops = new ArrayList<>();
        List<String> instr = new ArrayList<>();
        List<Crop> crop = new ArrayList<>();
        int n = s.nextInt();
        String asdf = s.nextLine();
        for (int i = 0; i <= n; i++) {
            if (i != 0){
                crops.add(s.nextLine());
            }
        }
        System.out.println("Enter farmer instr. To Stop press End");
        while(true){
            String i = s.nextLine();
            if (i.equals("End")){
                break;
            }
            instr.add(i);
        }
        int days = s.nextInt();
        System.out.println("Print farmer name.");
        asdf = s.nextLine();
        String fName = s.nextLine();
        Farmer farmer = new Farmer(fName, instr);
        System.out.println(farmer.getName());


        for (String se: crops){
            String[] splits = se.split(" ");
            switch (splits[1]) {
                case "Vegetable" -> {
                    Vegetable v = new Vegetable(splits[0]);
                    crop.add(v);
                }
                case "Fruit" -> {
                    Fruit f = new Fruit(splits[0]);
                    crop.add(f);
                }
                case "Cactus" -> {
                    Cactus c = new Cactus(splits[0]);
                    crop.add(c);
                }
                default -> System.out.println("You have validate wrong crop. Try Again.");
            }
        }



    }
}
