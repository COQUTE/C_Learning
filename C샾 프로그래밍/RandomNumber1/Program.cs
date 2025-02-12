using System;

namespace RandomNumber1
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rNum = new Random();
            int face = rNum.Next(3, 5);
            Console.WriteLine(face);
        }
    }
}
