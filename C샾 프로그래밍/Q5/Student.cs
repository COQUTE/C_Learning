using System;
using System.Collections.Generic;
using System.Text;

namespace Q5
{
    class Student
    {
        private string name;
        private int age;
        private int id;

        public void input()
        {
            Console.WriteLine("********input********");

            Console.Write("Enter your name:");
            name = Console.ReadLine();
            Console.Write("Enter your age:");
            age = int.Parse(Console.ReadLine());
            Console.Write("Enter your id:");
            id = int.Parse(Console.ReadLine());
        }

        public void output()
        {
            Console.WriteLine("********output********");

            if (age > 18)
                Console.WriteLine("adult\n" + $"Name:{name}\n" + $"Id:{id}");
            else
                Console.WriteLine("under age\n" + $"Name:{name}\n" + $"Id:{id}");
        }
    }
}
