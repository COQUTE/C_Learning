using System;

namespace Array1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[3];
            Array.Resize(ref arr, 5);

            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = int.Parse(Console.ReadLine());
            }

            foreach(int i in arr)
            {
                Console.WriteLine(i);
            }
        }
    }
}
