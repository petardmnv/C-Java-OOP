package com.company;

public class Note extends Item{
    private String text;

    public Note(String name, String text) {
        super(name);
        this.text = text;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Note name: " + this.getName() + "\n");
        sb.append("     Note text: " + this.text + "\n");
        return sb.toString();
    }

}
