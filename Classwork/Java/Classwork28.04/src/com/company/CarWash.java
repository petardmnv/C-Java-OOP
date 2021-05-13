package com.company;

import java.util.List;

public class CarWash {
    private int id;
    private int slots;
    private double cash;
    private List<Order> activeOrders;
    private List<Order> completedOrders;

    public CarWash(int id, int slots, double cash, List<Order> activeOrders, List<Order> completedOrders) {
        this.id = id;
        this.slots = slots;
        this.cash = cash;
        this.activeOrders = activeOrders;
        this.completedOrders = completedOrders;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getSlots() {
        return slots;
    }

    public void setSlots(int slots) {
        this.slots = slots;
    }

    public double getCash() {
        return cash;
    }

    public void setCash(double cash) {
        this.cash = cash;
    }

    public List<Order> getActiveOrders() {
        return activeOrders;
    }

    public void setActiveOrders(List<Order> activeOrders) {
        this.activeOrders = activeOrders;
    }

    public List<Order> getCompletedOrders() {
        return completedOrders;
    }

    public void setCompletedOrders(List<Order> completedOrders) {
        this.completedOrders = completedOrders;
    }

    public void addService(Service service){
        // Add service but where
    }

    private void addOrder(Automobile automobile, List<Service> services) throws Exception{
        if(this.activeOrders.size() >= this.slots){
            throw new Exception("Car Wash is full");
        }
        Order newOrder = new Order(automobile, services);
        newOrder.setId(hashCode());
        activeOrders.add(newOrder);
    }

    private void completeOrder(int id){
        for(Order order: this.activeOrders){
            if(order.getId() == id){
                int pr = 0;
                for(Service s: order.getService()){
                    pr += s.getPrice();
                }
                this.cash += order.getAutomobile().getMultiplayer() * pr;
                this.activeOrders.remove(order);
            }
        }
    }
}
