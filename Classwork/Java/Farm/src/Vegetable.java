public class Vegetable extends Crop{
    private String instrumentForHydrate;
    private String instrumentForGetting;

    public Vegetable(String name) {
        super(name, 2, 0, false, false);
        this.instrumentForHydrate = "Leika";
        this.instrumentForGetting = "Motika";
    }

    public String getInstrumentForHydrate() {
        return instrumentForHydrate;
    }

    public String getInstrumentForGetting() {
        return instrumentForGetting;
    }
}
