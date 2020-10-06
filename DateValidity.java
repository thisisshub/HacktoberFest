import java.util.*;
public class DateValidity{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter date in six digits (DDMMYY)");
    int date = sc.nextInt();
    int year = date % 100;
    date/=100;
    int month = date % 100;
    date/=100;
    boolean isLeap = (year%4==0);
    boolean isValid=true;
    if(month>12 || month==0 || date>31 || date==0){
      isValid=false;
    }
    if(month==2 && isLeap && date>28){
      isValid=false;
    }
    String mnth="";
    if(isValid){
      switch(month){
        case 1:mnth="January";break;
        case 2:mnth="February";break;
        case 3:mnth="March";break;
        case 4:mnth="April";break;
        case 5:mnth="May";break;
        case 6:mnth="June";break;
        case 7:mnth="July";break;
        case 8:mnth="August";break;
        case 9:mnth="September";break;
        case 10:mnth="October";break;
        case 11:mnth="November";break;
        case 12:mnth="December";break;
      }
      System.out.println(date+" "+mnth+" "+year+"\nVALID DATE");
    }else{
      System.out.println("INVALID DATE");
    }
  }
}
