package com.company;

import java.util.HashMap;
import java.util.Map;

public class Order {
    private int id;
    private Map<Dish, Integer> dishes = new HashMap<>();

    public Order(int id, Map<Dish, Integer> dishes) {
        this.id = id;
        this.dishes = dishes;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Map<Dish, Integer> getDishes() {
        return dishes;
    }

    public void setDishes(Map<Dish, Integer> dishes) {
        this.dishes = dishes;
    }
}
