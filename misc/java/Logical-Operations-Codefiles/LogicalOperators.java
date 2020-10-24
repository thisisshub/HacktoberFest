public class LogicalOperators{
   public static void main(String[] args){
   /*int age = 11;*
   /*int weight = 42;*/
int age=17;
   int weight =32;
   boolean b;

   /*b = age < 18 && weight >= 40;*/
  /* b = !(age <= 15 || weight <= 30);*/
   b = age < 15 ||( age < 18 && weight < 40);

   System.out.println(b);


   }
}
