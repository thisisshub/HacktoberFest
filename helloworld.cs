using System;
namespace hello
{
    class CalcAvgPerc
    {
        static void Main(string[] args)
        {
            int a = 30, b = 20;
            Console.WriteLine("Calculating..");
            System.Threading.Thread.Sleep(2000);
            Console.WriteLine("Adding the two numbers");
            Console.WriteLine("Addition of {0} + {1} is : {2}", a, b, a + b);
            Console.WriteLine("Subtracting two numbers");
            Console.WriteLine("Subtracting of {0} - {1} is: {2}", a, b, a - b);
            Console.WriteLine("Multiplication of two numbers");
            Console.WriteLine("Multiplication of {0} * {1} is : {2}", a, b, a * b);
            Console.WriteLine("Dividing of two numbers");
            Console.WriteLine("Dividing of {0}/{1} is:{2}", a, b, (float)a / b);
            Console.ReadKey();
        }
    }
}
