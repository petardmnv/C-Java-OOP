package com.company;

public class NotEnoughAmountException extends Throwable {
    public NotEnoughAmountException(String s) {
        super(s);
    }
}
