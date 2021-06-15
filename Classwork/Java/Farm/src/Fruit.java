public class Fruit extends Crop{
    private String instrumentForHydrate;
    private String instrumentForGetting;

    public Fruit(String name) {
        super(name, 4, 0, false, false);
        this.instrumentForHydrate = "Leika";
        this.instrumentForGetting = "Stulba";
    }

    public String getInstrumentForHydrate() {
        return instrumentForHydrate;
    }

    public String getInstrumentForGetting() {
        return instrumentForGetting;
    }
}
