using System;

namespace Test2
{
    class Program
    {
        static void Main(string[] args)
        {
            int a;
            double b;
            string name = Console.ReadLine();
            a = int.Parse(Console.ReadLine());
            b = double.Parse(Console.ReadLine());
            Console.WriteLine(name);
            Console.WriteLine("Sum : " + (a + b));
        }
    }
}
