using System;
namespace csharp{
class Addition{
		static void Main(string[] args){
		int firstNumber=0;
		int secondNumber=0;
		Console.WriteLine("Enter your first number:");
		firstNumber=Convert.ToInt32(Console.ReadLine());
		Console.WriteLine("Enter your second number:");
		secondNumber=Convert.ToInt32(Console.ReadLine());
		int totalSum= firstNumber+secondNumber;

		Console.Write("The sum of firstNumber{0} and secondNumber{1} is ={2}", firstNumber,secondNumber,totalSum);

		}
}
}

		
