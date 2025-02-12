using System;
using System.Linq;
using System.Collections.Generic;

namespace LINQandListCollection
{
    class Program
    {
        static void Main(string[] args)
        {
            var items = new List<string>();
            items.Add("aQua");
            items.Add("RusT");
            items.Add("yElLow");
            items.Add("rEd");

            Console.Write("items contains:");
            foreach (var item in items)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine();

            var startsWithR =
                from item in items
                let uppercaseString = item.ToUpper()
                where uppercaseString.StartsWith("R")
                orderby uppercaseString
                select uppercaseString;

            Console.Write("results of query startsWithR:");
            foreach (var item in startsWithR)
            {
                Console.Write(" " + item);
            }
            Console.WriteLine();
        }
    }
}
