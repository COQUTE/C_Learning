using System;
using System.Linq;

namespace C샾시험
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[] { 2, 9, 5, 0, 3, 7, 1, 4, 8, 5 };

            Console.Write("Original Array:");
            foreach(var value in arr)
            {
                Console.Write(" " + value);
            }
            Console.WriteLine();

            Console.Write("Array with even number:");
            var even =
                from value in arr
                where value % 2 == 0 && value != 0
                select value;
            foreach(var v in even)
            {
                Console.Write(" " + v);
            }
            Console.WriteLine();

            Console.Write("Original array, sorted in descending order:");
            var des =
                from value in arr
                orderby value descending
                select value;
            foreach(var d in des)
            {
                Console.Write(" " + d);
            }
            Console.WriteLine();

            Console.Write("Sorted array from b) in descending order:");
            var evenDes =
                from value in even
                orderby value descending
                select value;
            foreach(var ed in evenDes)
            {
                Console.Write(" " + ed);
            }
            Console.WriteLine();

            Console.Write("Array greater than 5, sorted in descending order:");
            var biggerFiveDes =
                from value in arr
                where value > 5
                orderby value descending
                select value;
            foreach(var bfd in biggerFiveDes)
            {
                Console.Write(" " + bfd);
            }
            Console.WriteLine();
        }
    }
}
