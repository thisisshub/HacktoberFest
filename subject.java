package com.subjectmarks;
import java.util.Scanner;
import java.text.DecimalFormat;

public class SubjectMarks {

    public static void main(String[] args) {

        int tmarks = 500;
        int phy,chem,maths,eng,comp;
        float sum,percent;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter marks in physics");
        phy=sc.nextInt();
        System.out.println("Enter marks in chemistry");
        chem=sc.nextInt();
        System.out.println("Enter marks in mathematics");
        maths=sc.nextInt();
        System.out.println("Enter marks in english");
        eng=sc.nextInt();
        System.out.println("Enter marks in computer science");
        comp=sc.nextInt();
        sum = phy+chem+maths+eng+comp;
        percent = (sum/tmarks)*100;
        DecimalFormat numberFormat = new DecimalFormat("#.00");
        System.out.println("Percentage: "+numberFormat.format(percent));
        if((percent<=100 && percent>=90) && (phy>=40 && chem>=40 && maths>=40 && eng>=40 && comp>=40)){
            System.out.println("Grade: A+");
        }
        else if((percent<90 && percent>=80) && (phy>=40 && chem>=40 && maths>=40 && eng>=40 && comp>=40)){
            System.out.println("Grade: A");
        }
        else if((percent<80 && percent>=70) && (phy>=40 && chem>=40 && maths>=40 && eng>=40 && comp>=40)){
            System.out.println("Grade: B+");
        }
        else if((percent<70 && percent>=60) && (phy>=40 && chem>=40 && maths>=40 && eng>=40 && comp>=40)){
            System.out.println("Grade: B");
        }
        else if((percent<60 && percent>=50) && (phy>=40 && chem>=40 && maths>=40 && eng>=40 && comp>=40)){
            System.out.println("Grade: C+");
        }
        else if((percent<50 && percent>=40) && (phy>=40 && chem>=40 && maths>=40 && eng>=40 && comp>=40)){
            System.out.println("Grade: C");
        }
        else{
            System.out.println("Grade: D (Fail)");
        }

    }
}
