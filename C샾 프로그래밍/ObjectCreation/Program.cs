using System;

namespace ObjectCreation
{
    class Student
    {
        private string name;
        private int id;

        public void input()
        {
            name = Console.ReadLine();
            id = int.Parse(Console.ReadLine());
        }

        public void output()
        {
            Console.WriteLine("*************");
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Id: " + id);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Student obj = new Student();
            obj.input();
            obj.output();
        }
    }
}
