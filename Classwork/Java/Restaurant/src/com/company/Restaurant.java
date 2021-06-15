package com.company;

import java.util.ArrayList;
import java.util.List;

public class Restaurant {
    private List<Dish> dishes = new ArrayList<>();
    private List<Chef> chefs = new ArrayList<>();
    private List<Waiter> waiters = new ArrayList<>();
    private Storage storage;
    private double money;
    private List<Order> activeOrders = new ArrayList<>();
    private List<Order> completedOrders = new ArrayList<>();
    private List<Order> failedOrders = new ArrayList<>();

    public Restaurant(List<Dish> dishes, List<Chef> chefs, List<Waiter> waiters, Storage storage, double money) {
        this.dishes = dishes;
        this.chefs = chefs;
        this.waiters = waiters;
        this.storage = storage;
        this.money = money;
    }

    synchronized public List<Order> getActiveOrders() {
        return activeOrders;
    }

    public void setActiveOrders(List<Order> activeOrders) {
        this.activeOrders = activeOrders;
    }

    public void addOrder(Order o) throws Exception{
        if (o.getDishes().isEmpty()){
            throw new Exception("There are no dishes in given order!");
        }
        activeOrders.add(o);
    }

    public void completeOrder(int id) throws Exception{
        boolean isIdValid = false;
        for (Order o: activeOrders) {
            if(o.getId() == id){
                isIdValid = true;
                completedOrders.add(o);
            }
        }
        if(!isIdValid){
            throw new Exception("Order with this id is not found");
        }
    }

    public void addChef(Chef chef) throws Exception{
        if (chefs.contains(chef)){
            throw new Exception("This chef is already in the kitchen!");
        }
        chefs.add(chef);
    }
    public void addWaiter(Waiter waiter) throws Exception{
        if (waiters.contains(waiter)){
            throw new Exception("This waiter is already in the restaurant!");
        }
        waiters.add(waiter);
    }
}
