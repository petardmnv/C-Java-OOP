package com.company;

public class Waiter implements Runnable{
    private String name;
    private Restaurant restaurant;

    public Waiter(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {
        while(true){
            Order order = restaurant.getCookedOrder();
            if (order != null) {
                System.out.println(name + "Serving order: " + order);
                restaurant.completeOrder(order.getId());
                try {
                    Thread.sleep(2 * 1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
