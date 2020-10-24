/*In a right triangle, the square of the length of one side is equal to the sum of the squares of the lengths of the other two sides.  Write a program that prompts the user to enter the lengths of three sides of a triangle and then outputs a message indicating whether the triangle is a right triangle.*/

using System;
namespace Assignment
{
	class triangle
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Enter the lengths of the three sides of a triangle");
			int first= int.Parse(Console.ReadLine());
			int second = int.Parse(Console.ReadLine());
			int third = int.Parse(Console.ReadLine());
			if(first>0 && second>0 && third>0)
			{
			check(first, second, third);
			}
			else
			{
				Console.WriteLine("Invalid triangle");
			}
		}//end of main function
		
		public static void check(int first, int second, int third)
		{
			double a = Math.Pow(first,2);
			double b = Math.Pow(second,2);
			double c = Math.Pow(third,2);
			if((a==(b+c)) || (b==(a+c)) || (c==(a+b)))
			{
				Console.WriteLine("The triangle is a right angled triangle.");
			}
			else
			{
				Console.WriteLine("The triangle is not a right angled triangle.");
			}
		}
	}
}