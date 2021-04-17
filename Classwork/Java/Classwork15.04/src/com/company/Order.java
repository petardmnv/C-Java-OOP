package com.company;

import java.util.ArrayList;
import java.util.List;

public class Order {
    private int id;
    private int buyer_id;
    private Address user_address;
    private Status status;
    private List<Item> products = new ArrayList<>();
    private int quantity;
    private int price;

    public Order(int id, int buyer_id, Address user_address, Status status, List<Item> products, int quantity, int price) {
        this.id = id;
        this.buyer_id = buyer_id;
        this.user_address = user_address;
        this.status = status;
        this.products = products;
        this.quantity = quantity;
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getBuyer_id() {
        return buyer_id;
    }

    public void setBuyer_id(int buyer_id) {
        this.buyer_id = buyer_id;
    }

    public Address getUser_address() {
        return user_address;
    }

    public void setUser_address(Address user_address) {
        this.user_address = user_address;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    public List<Item> getProducts() {
        return products;
    }

    public void setProducts(List<Item> products) {
        this.products = products;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }
}
