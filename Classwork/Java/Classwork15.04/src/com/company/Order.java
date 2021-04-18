package com.company;

import java.util.ArrayList;
import java.util.List;

public class Order {
    private int id;
    private int buyerId;
    private Address userAddress;
    private Status status;
    private List<Item> products = new ArrayList<>();
    private int quantity;
    private int price;

    public Order(int id, int buyerId, com.company.Address userAddress, com.company.Status status, List<Item> products, int quantity, int price) {
        this.id = id;
        this.buyerId = buyerId;
        this.userAddress = userAddress;
        this.status = status;
        this.products = products;
        this.quantity = quantity;
        this.price = price;
    }
}
