package com.company;

import java.util.Map;

public class Chef implements Runnable{
    private String name;
    private Restaurant restaurant;
    public Chef(String name, Restaurant restaurant)
    {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {
        while(true){
            Order order = restaurant.getOrder();
            if (order != null) {
                System.out.println(name + " taking order: " + order.toString());
                try {
                    double price = cookingOrder(order);
                    restaurant.addCookedOrder(order);
                    restaurant.setMoney(restaurant.getMoney() + price);
                } catch (Exception ex) {
                    System.out.println(ex.getMessage());
                    restaurant.failOrder(order);
                }
            }

            try {
                Thread.sleep(2 * 1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public double cookingOrder(Order order) throws Exception {
        double finalPrice = 0;
        int cookingTime = 0;

        for(Map.Entry<Dish, Integer> e : order.getDishes().entrySet()){
            Dish dish = e.getKey();
            Integer quantity = e.getValue();
            for(Map.Entry<Product, Integer> p : dish.getRecipe().entrySet()){
                if(p.getValue() * quantity > restaurant.getStorage().getProductsList().get(p.getKey())){
                    throw new Exception("Not enough products!");
                }else{
                    restaurant.getStorage().getProduct(p.getKey(), p.getValue() * quantity);
                }

            }
            finalPrice += dish.getSalePrice() * quantity;
            cookingTime += dish.getTimeToCook() * quantity;
        }
        try {
            Thread.sleep(cookingTime);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        return finalPrice;
    }

}
