import java.util.*;

public class Main {

    public static void main(String[] args) {
        List<Animal> animals = new ArrayList<>();
        animals.add(new Animal("Kon", "kopitno", "bozainik"));
        animals.add(new Animal("riba", "morski", "vodni"));

        System.out.println(animals.get(0).hashCode());

        //Map<Animal, Animal> animals2 = new HashMap();
        Map<Integer, Animal> animals2 = new TreeMap();

        Animal riba = new Animal("riba", "morski", "vodni");
        Animal kon = new Animal("Kon", "kopitno", "bozainik")   ;

        animals2.put(riba.hashCode(), riba);
        animals2.put(kon.hashCode(), kon);

        for (Map.Entry<Integer, Animal> a: animals2.entrySet()){
            System.out.println(a.getValue().toString());
        }

        Set<Animal> animals3 = new HashSet<>();
        animals3.add(new Animal("Kon", "kopitno", "bozainik"));
        animals3.add(new Animal("riba", "morski", "vodni"));
        animals3.add(new Animal("rwiba", "morski", "vodni"));

        for (Animal a: animals3){
            System.out.println(a);
        }
    }
}
