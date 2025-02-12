using System;

namespace Q2_3
{
    class Program
    {
        static void Main(string[] args)
        {
            Random randomNumber = new Random();

            // 0 to 24
            Console.WriteLine(randomNumber.Next(24));
            // 1 to 6
            Console.WriteLine(randomNumber.Next(1, 7));
            // 10 to 109
            Console.WriteLine(randomNumber.Next(10, 110));
            // 100 to 149
            Console.WriteLine(randomNumber.Next(100, 150));
            // -5 to 4
            Console.WriteLine(randomNumber.Next(-5, 5));
            // 12 to 33
            Console.WriteLine(randomNumber.Next(12, 34));
        }
    }
}
