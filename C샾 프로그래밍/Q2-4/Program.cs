using System;

namespace Q2_4
{
    class Program
    {
        static void Main(string[] args)
        {
            int length;

            Console.Write("Enter size:");
            length = int.Parse(Console.ReadLine());

            double[] arr = new double[1];
            Array.Resize(ref arr, length);

            Console.WriteLine($"The size of the array: {arr.Length}");

            for (var count = 0; count < arr.Length; count++)
            {
                Console.Write($"Enter number {count + 1}: ");
                arr[count] = double.Parse(Console.ReadLine());
            }

            Console.WriteLine("The numbers in reverse order:");
            for (var index = arr.Length - 1; index >= 0; index--)
            {
                Console.Write(arr[index] + "  ");
            }
            Console.Write("\n");
        }
    }
}
