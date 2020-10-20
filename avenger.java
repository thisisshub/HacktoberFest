package com.avengers;
import java.util.Scanner;

public class Avenger {

     String name,weapon,planet;
     int age,power;

    Scanner sc = new Scanner(System.in);

    public void getDetails() {
        System.out.print("Enter Name : ");
        name = sc.nextLine();
        System.out.print("Enter Age : ");
        age = sc.nextInt();
        System.out.print("Enter Power : ");
        power = sc.nextInt();
        System.out.print("Enter Weapon : ");
        weapon = sc.next();
        System.out.print("Enter Planet : ");
        planet =sc.next();
    }

    public void displayDetails() {
            System.out.println("Name: " + name);
            System.out.println("Age: " + age);
            System.out.println("Power: " + power);
            System.out.println("Weapon: " + weapon);
            System.out.println("Planet: " + planet);
        }
}
