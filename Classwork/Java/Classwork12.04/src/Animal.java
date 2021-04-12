import java.util.Objects;

public class Animal {
    String species;
    String family;
    String order;

    public Animal(String species, String family, String order) {
        this.species = species;
        this.family = family;
        this.order = order;
    }

    @Override
    public int hashCode() {
        return Objects.hash(species, family, order);
    }

    @Override
    public String toString() {
        return "Namr" + this.species;
    }
}
