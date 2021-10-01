package com.practice;

public class buubleSort {
    public static void main(String[] args) {

        System.out.println("Increasing star pattern ");
        for (int i = 1; i <= 5; i++ ) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }

        System.out.println();

        System.out.println("Decreasing star pattern ");
        for (int i = 1; i <= 5; i++ ) {
            for (int j = i; j < 5; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }


    }
}
