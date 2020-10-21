public class SwitchCaseDemo{
   public static void main(String[] args){
	int day = 3;
//int day=0;
//int day=-1;
//int day=15;
//int day=4;
	String dName = "";
switch(day) {
case 0:
dName = "Sunday";
break;
case 1:
dName = "Monday";
break;
case 2:
dName = "Tuesday";
break;
case 3:
dName = "Wednesday";
break;
case 4:
dName = "Thursday";
//break;
case 5:
dName = "Friday";
break;
case 6:
dName = "Saturday";
break;
default:
dName = "Wrong Choice";
break;

}
System.out.println(dName);

   }
}
