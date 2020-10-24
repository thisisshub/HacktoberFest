/*Write a C# application that mimics a calculator.  The program should take as input to integers and an arithmetic operation (+, -, * or /) to be performed.  It should then output the numbers, the operator and the result.  (For division, if the denominator is zero, output an appropriate message).*/

using System;
namespace Assignment
{
	class Calculator
	{
		public static void Main (string[] args)
		{
			string confirm;
			do
			{
				Console.WriteLine("Enter the two integers for calculation:");
				int first=Convert.ToInt32(Console.ReadLine());
				int second=Convert.ToInt32(Console.ReadLine());
				Console.WriteLine("Enter the arithmetic operation to be performed(+,-,*,/):");
				string operation=Console.ReadLine();
				switch (operation)
				{
					case "+":
						Addition(first,second);
						break;
					case "-":
						Subtraction(first,second);
						break;
					case "*":
						Multiplication(first,second);
						break;
					case "/":
						Division(first, second);
						break;
					default:
						Console.WriteLine("Invalid operation choice");
						break;
					
				}
				Console.WriteLine("Do you wish to continue(Y/N):");
				confirm=Console.ReadLine();
			}
			while(confirm=="y");
			System.Console.ReadKey();
		} // main function ends
		
		public static void Addition(int first, int second)
		{
			int result= first + second;
			Console.WriteLine("{0} + {1} = {2}", first, second, result);
			
		
		}
		
		public static void Subtraction( int first, int second)
		{
			int result= first - second;
			Console.WriteLine("{0} - {1} = {2}", first, second, result);
		}
		
		public static void Multiplication( int first, int second)
		{
			int result= first * second;
			Console.WriteLine("{0} * {1} = {2}", first, second, result);	
		}
		
		public static void Division(int first, int second)
		{
			int a=0, b=0;
			if(first>second) // making 'a' always the greater one
			{
			 a =first;
			 b =second;
			}
			else
			{
			 a=second;
			 b=first;
			}
			if(b==0)
			{
			Console.WriteLine("The result is infinite!");
			}
			else
			{
			int result=a/b;
			Console.WriteLine("{0} / {1} = {2}", a, b, result);
			}
		}
	}
}