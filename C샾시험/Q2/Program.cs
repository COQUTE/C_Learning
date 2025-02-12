using System;

namespace Q2
{
    class Program
    {
        static void Main(string[] args)
        {
            Random dots = new Random();

            int[] freq = new int[7];

            for (int count = 0; count < 36000; count++)
            {
                freq[dots.Next(1, 7)]++; // dice 1
                freq[dots.Next(1, 7)]++; // dice 2
            }

            Console.WriteLine("Face    Frequency (die1 + die2)");

            for (int index = 1; index <= 6; index++)
            {
                Console.Write(index + "       ");

                Console.WriteLine(freq[index]);
            }
        }
    }
}
