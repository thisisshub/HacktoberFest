#include<stdio.h>

int check_palindrome(int num){

   static int reverse_num=0,rem;

   if(num!=0){
      rem=num%10;
      reverse_num=reverse_num*10+rem;
      check_palindrome(num/10);
   }

   return reverse_num;
}
int main(){
   int num, reverse_num;

   printf("Enter a number: ");
   scanf("%d",&num);

   reverse_num = check_palindrome(num);

   if(num==reverse_num)
      printf("%d is a palindrome number",num);
   else
      printf("%d is not a palindrome number",num);

   return 0;
}
