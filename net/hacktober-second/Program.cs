using System;
using System.Text.RegularExpressions;

namespace hacktober_second
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(FormatPhoneNumberForBrasil("You can +55 send 11 any brazilian 99999 here 8888", true));
        }

        private static string FormatPhoneNumberForBrasil(string phoneNumber, bool allowNumberFormating)
        {
            if (string.IsNullOrEmpty(phoneNumber))
            {
                return phoneNumber;
            }

            phoneNumber = Regex.Replace(phoneNumber, @"[^\d]", "");

            if (allowNumberFormating == false)
            {
                return phoneNumber;
            }

            //Números que possuem menos de 10 dígitos podem ser short-codes
            if (phoneNumber.Length < 10) return phoneNumber;

            //As vezes o DDD pode começar com 0, neste caso o 0 precisa ser removido
            if (phoneNumber.StartsWith("0"))
            {
                phoneNumber = phoneNumber.Remove(0, 1);
            }

            // O número possui 55 + DDD + 9 dígitos
            if (phoneNumber.Length == 13)
            {
                return phoneNumber;
            }

            // O número possui 55 + DDD + 8 dígitos
            if (phoneNumber.Length == 12)
            {
                phoneNumber = phoneNumber.Insert(4, "9");
                return phoneNumber;
            }

            //O número possui DDD + 9 Dígitos
            if (phoneNumber.Length == 11)
            {
                return $"55{phoneNumber}";
            }

            //Se o número possuir exatamente 10 dígitos, significa que está faltando o nono dígito
            if (phoneNumber.Length == 10)
            {
                phoneNumber = phoneNumber.Insert(2, "9");
                return $"55{phoneNumber}";
            }

            return phoneNumber;
        }
    }
}
