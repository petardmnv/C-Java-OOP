import java.util.ArrayList;
import java.util.List;

public class Farmer {
    private String name;
    private List<String> instruments = new ArrayList<>();

    public Farmer(String name, List<String> instruments) {
        this.name = name;
        this.instruments = instruments;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<String> getInstruments() {
        return instruments;
    }

    public void setInstruments(List<String> instruments) {
        this.instruments = instruments;
    }

    /*public void work(List<Crop> crops){
        for(Crop c: crops){
            if (c.getDays() == 2){
                if (! this.instruments.contains("Leika")){
                    c.setDead(true);
                }
                if (c.isIs_Gotten()){
                    if ()
                }
            }
        }
    }*/
}
