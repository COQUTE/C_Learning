using System;
using System.Collections.Generic;
using System.Text;

namespace MultipleClasses
{
    class Class1
    {
        private string name;
        private int id;

        public void input()
        {
            name = Console.ReadLine();
            id = int.Parse(Console.ReadLine());
        }

        public void display()
        {
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Id: " + id);
        }
    }
}
