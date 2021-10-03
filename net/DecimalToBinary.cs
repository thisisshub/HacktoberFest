using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DecimalToBinary
{
    class Program
    {
        static void binary(int number)
        {
            int left, result;
            if (number <= 1)
            {
                Console.Write(number);
                return;
            }
            left = number % 2;
            result = number / 2;
            binary(result);
            Console.Write(left);
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Input number:");
            string dec = Console.ReadLine();
            binary(Convert.ToInt32(dec));
            Console.ReadLine();
        }
    }
}
