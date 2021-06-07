package com.company;

import java.util.HashMap;
import java.util.Map;

public class Storage {
    private Map<Product, Integer> productsList = new HashMap<>();

    public Storage(Map<Product, Integer> productsList) {
        this.productsList = productsList;
    }

    public Map<Product, Integer> getProductsList() {
        return productsList;
    }

    public void setProductsList(Map<Product, Integer> productsList) {
        this.productsList = productsList;
    }

    public void addProduct(Product p, int quantity) throws Exception{
        if (quantity <= 0){
            throw new Exception("Invalid product quantity!");
        }
        if (!productsList.containsKey(p)){
            productsList.put(p, 0);
        }
        productsList.replace(p, productsList.get(p) + quantity);
    }
    public int getProduct(Product p, int quantity) throws Exception{
        if (quantity <= 0){
            throw new Exception("Invalid product quantity!");
        }
        if (!productsList.containsKey(p)){
            throw new Exception("Product is not available in the storage!");
        }
        if (productsList.get(p) < quantity){
            throw new Exception("Product quantity is smaller than needed quantity!");
        }

        productsList.replace(p, productsList.get(p) - quantity);
        return quantity;
    }
}
