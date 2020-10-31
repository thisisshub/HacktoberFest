import java. util.*;
class WordPile
{
char ch[];
int capacity;
int top;
public WordPile(int cap)
{
capacity=cap;
top=-1;
ch=new char[capacity];
}
public void pushChar(char v)
{
if(top+1==capacity)
System.out.println("WordPile is full");
else
ch[++top]=v;
}
public char popChar()
{
if(top==-1)
return '\\';
else
return ch[top--];
}
//main written so that the program can be executed
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.print("How many characters?");
int n=sc.nextInt();
if(n>20)
n=20;
WordPile obj=new WordPile(n);
outer:
while(true)
{
System.out.println("1. PushCharacter");
System.out.println("2. Pop Character");
System.out.print("Enter your choice:");
int choice=sc.nextInt();
switch(choice)             //switch case
{
case 1:
System.out.print("Enter the character:");
char c=sc.next().charAt(0);
obj.pushChar(c);
break;
case 2:
c=obj.popChar();
if(c=='\\')
System.out.println("Empty stack.");
else
System.out.println(c+" popped.");
break;
default:
break outer;
}
}
}
}// end of the class 
