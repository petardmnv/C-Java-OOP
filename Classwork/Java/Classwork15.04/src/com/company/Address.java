package com.company;

public class Address {
    private Country country;
    private String city;
    private String street;
    private int street_number;
    private int apartment_number;

    public Address(Country country, String city, String street, int street_number, int apartment_number) {
        this.country = country;
        this.city = city;
        this.street = street;
        this.street_number = street_number;
        this.apartment_number = apartment_number;
    }

    public Country getCountry() {
        return country;
    }

    public void setCountry(Country country) {
        this.country = country;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public int getStreet_number() {
        return street_number;
    }

    public void setStreet_number(int street_number) {
        this.street_number = street_number;
    }

    public int getApartment_number() {
        return apartment_number;
    }

    public void setApartment_number(int apartment_number) {
        this.apartment_number = apartment_number;
    }
}
