public class ParkingPlace {
    private int number;
    private double area;
    private String personName;
    private String personSurname;
    private String description;

    public ParkingPlace(int number, double area, String personName, String personSurname, String description) {
        this.number = number;
        this.area = area;
        this.personName = personName;
        this.personSurname = personSurname;
        this.description = description;
    }

    @Override
    public String toString() {
        return "ParkingPlace{" +
                "number=" + number +
                ", area=" + area +
                ", personName='" + personName + '\'' +
                ", personSurname='" + personSurname + '\'' +
                ", description='" + description + '\'' +
                '}';
    }
}
