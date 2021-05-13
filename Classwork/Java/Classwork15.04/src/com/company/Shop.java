package com.company;

import java.util.*;

public class Shop {
    private List<Order> orders = new ArrayList<>();
    private Country shopCountry;
    private List<Country> shippingToCountries = new ArrayList<>();
    Set<User> users = new HashSet<>();
    Map<Item, Integer> items = new HashMap<>();

    public void registerCustomer(User user){
        //TODO Error handling
        user.setId(user.hashCode());
        users.add(user);
    }

    public void addItem(Item item, int amount){
        //TODO Error handling
        item.setId(item.hashCode());
        if (this.items.containsKey(item)){
            this.items.put(item, this.items.get(item) + amount);
        }else {
            this.items.put(item, amount);
        }
    }

    public void removeItem(Item item , int amount) throws NoSuchElementException, NotEnoughAmountException {
        if (this.items.containsKey(item)){
            if (this.items.get(item) < amount){
                throw new NotEnoughAmountException("Amount is too big!");
            }
            this.items.put(item, this.items.get(item) - amount);
        }else {
            throw new NoSuchElementException("No such item in items!");
        }
    }

    public void addItemToCart(int ID, int amount){
        if (){

        }
    }
}

/*
registerCustomer(Customer) - Customer обекта съдържа цялата информация с изключение на ID-то. Ако някое поле е празно, да се хвърли грешка с липсващото поле.
Метода трябва да генерира произволно ID и да добави новия клиент към списъка с клиенти. (SET)

addItem(Item, amount) - Item обекта съдържа цялата информация с изключение на ID-то. Ако някое поле е празно, да се хвърли грешка с липсващото поле.
Метода трябва да генерира произволно ID и да добави новия артикул към списъка с артикули с посочената наличност.
Ако бъде подаден Item обект с попълнено ID, то тогава количеството на посочения артикул трябва да се увеличи. (MAP)

removeItem(Item, amount) - от наличностите трябва да бъде извадено посоченото количество. Ако искаме да извадим по-голямо количество от наличното -> грешка.
Ако item-a не съществува -> грешка.

addItemToCart(ID, amount) - добавя артикула към активната кошница с определеното количество.

checkoutCart() - ако в активната кошница е празна -> грешка.
Проверява дали добавените количества са налични, ако не -> грешка
Ако са налични създава поръчка в статус Open и активния потребител.
Ако активния потребител няма попълнена информация, то трябва да се създаде гост с произволно ID

shipOrder(ID) - променя статус на поръчката на Shipped. Ако не е намерено такова ID -> грешка
Ако страната до която трябва да бъде доставена поръчката не е в списъка на държави до които доставя магазина -> грешка и сменяме статус на поръчката на Failed

completeOrder(ID) - променя статус на поръчката на Completed. Ако не е намерено такова ID -> грешка

failOrder(ID) - променя статус на поръчката на Failed. Ако не е намерено такова ID -> грешка
 */
