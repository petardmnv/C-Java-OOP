package com.company;

public class MotherBoard implements IPart{
    private String chipSet;

    public MotherBoard(String chipSet, int chipSetPower) {
        this.chipSet = chipSet;
    }

    public String getChipSet() {
        return chipSet;
    }

    public void setChipSet(String chipSet) {
        this.chipSet = chipSet;
    }

    @Override
    public PowerData getConsumption() {
        double typicalPowerFromChipName = switch (chipSet) {
            case "am1" -> 25;
            case "am2" -> 35;
            case "am3" -> 50;
            default -> 30;
        };
        final double typicalPower = typicalPowerFromChipName;

        return new PowerData(typicalPower, typicalPower, typicalPower);
    }
}
