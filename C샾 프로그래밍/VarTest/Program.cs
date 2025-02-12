using System;

namespace VarTest
{
    class Program
    {
        static void Main(string[] args)
        {
            var arr = new[] { 1, 2, 3 };

            foreach(var i in arr)
            {
                Console.WriteLine(i);
            }
        }
    }
}
