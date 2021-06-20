public class Crop {
    private String name;
    private int days;
    private int currDays;
    private boolean isDead;
    private boolean is_Gotten;

    public Crop(String name, int days, int currDays, boolean isDead, boolean is_Gotten) {
        this.name = name;
        this.days = days;
        this.currDays = currDays;
        this.isDead = isDead;
        this.is_Gotten = is_Gotten;
    }

    public int getDays() {
        return days;
    }

    public void setDays(int days) {
        this.days = days;
    }

    public int getCurrDays() {
        return currDays;
    }

    public void setCurrDays(int currDays) {
        this.currDays = currDays;
    }

    public boolean isDead() {
        return isDead;
    }

    public void setDead(boolean dead) {
        isDead = dead;
    }

    public boolean isIs_Gotten() {
        return is_Gotten;
    }

    public void setIs_Gotten(boolean is_Gotten) {
        this.is_Gotten = is_Gotten;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
