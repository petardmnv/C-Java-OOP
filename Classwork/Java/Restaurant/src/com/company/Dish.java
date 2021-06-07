package com.company;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class Dish {
    private String name;
    private Map<Product, Integer> recipe = new HashMap<>();
    private int timeToCook;

    public Dish(String name, Map<Product, Integer> recipe, int timeToCook) {
        this.name = name;
        this.recipe = recipe;
        this.timeToCook = timeToCook;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Map<Product, Integer> getRecipe() {
        return recipe;
    }

    public void setRecipe(Map<Product, Integer> recipe) {
        this.recipe = recipe;
    }

    public int getTimeToCook() {
        return timeToCook;
    }

    public void setTimeToCook(int timeToCook) {
        this.timeToCook = timeToCook;
    }


    public double getSalePrice(){
        // That is strange but works
        return recipe.keySet().stream().map(x -> x.getPrice() * 2).collect(Collectors.toList()).stream().mapToDouble(Double::doubleValue).sum();
    }
}
