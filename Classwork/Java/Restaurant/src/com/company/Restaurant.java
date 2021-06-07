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
    
}
