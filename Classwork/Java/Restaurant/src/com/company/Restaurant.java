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
    private List<Order> takenOrders = new ArrayList<>();
    private List<Order> cookedOrders = new ArrayList<>();
    private List<Order> completedOrders = new ArrayList<>();
    private List<Order> failedOrders = new ArrayList<>();

    public Restaurant(List<Dish> dishes, Storage storage, double money) {
        this.dishes = dishes;
        this.storage = storage;
        this.money = money;
    }

    synchronized public List<Order> getActiveOrders() {
        return activeOrders;
    }

    public void setActiveOrders(List<Order> activeOrders) {
        this.activeOrders = activeOrders;
    }

    public synchronized Order getCookedOrder() {
        if(cookedOrders.size() == 0){
            return null;
        }
        Order o = cookedOrders.get(0);
        cookedOrders.remove(o);
        return o;
    }

    public synchronized Storage getStorage() {
        return storage;
    }

    public synchronized void setStorage(Storage storage) {
        this.storage = storage;
    }

    public synchronized double getMoney() {
        return money;
    }

    public synchronized void setMoney(double money) {
        this.money = money;
    }

    public synchronized void addOrder(Order o) throws Exception{
        if (o.getDishes().isEmpty()){
            throw new Exception("There are no dishes in given order!");
        }
        activeOrders.add(o);
    }

    public synchronized Order getOrder(){
        if (activeOrders.isEmpty()){
            return null;
        }
        Order currentOrder = activeOrders.get(0);
        activeOrders.remove(currentOrder);
        takenOrders.add(currentOrder);
        return currentOrder;
    }

    public synchronized void addCookedOrder(Order o){
        takenOrders.remove(o);
        cookedOrders.add(o);
    }


    public synchronized void completeOrder(int id){
        boolean isIdValid = false;
        for (Order o: cookedOrders) {
            if(o.getId() == id){
                isIdValid = true;
                completedOrders.add(o);
            }
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

    public synchronized void failOrder(Order o){
        takenOrders.remove(o);
        failedOrders.add(o);
    }

    public void cook(){

            for (Chef c : chefs) {
                c.run();
            }
            for (Waiter w : waiters) {
                w.run();
            }
    }
}
