public class Cactus extends Crop{
    private String instrumentForGetting;

    public Cactus(String name) {
        super(name, 3, 0, false, false);
        this.instrumentForGetting = "Rukavici";
    }

    public String getInstrumentForGetting() {
        return instrumentForGetting;
    }
}
