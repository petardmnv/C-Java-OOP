package com.company;

import java.util.List;
import java.util.Objects;

public class Order {
    private int id;
    private Automobile automobile;
    private List<Service> service;

    public Order(Automobile automobile, List<Service> service) {
        this.automobile = automobile;
        this.service = service;
    }

    @Override
    public int hashCode() {
        return Objects.hash(this.automobile, this.service);
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Automobile getAutomobile() {
        return automobile;
    }

    public void setAutomobile(Automobile automobile) {
        this.automobile = automobile;
    }

    public List<Service> getService() {
        return service;
    }

    public void setService(List<Service> service) {
        this.service = service;
    }
}
