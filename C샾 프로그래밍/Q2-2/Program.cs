using System;

namespace Q2_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var die = new Random(); // The object of class Random
            var frequency = new int[7];

            Console.WriteLine($"{"Face"}{"Frequency(die1 and die2)", 28}");

            for (var count = 0; count < 36000; count++)
            {
                frequency[die.Next(1, 7)]++; // die1 (range -> 1 ~ 6)
                frequency[die.Next(1, 7)]++; // die2 (range -> 1 ~ 6)
            }

            for (var index = 1; index < frequency.Length; index++)
            {
                Console.WriteLine($"{index, 4}{frequency[index], 9}");
            }
        }
    }
}
