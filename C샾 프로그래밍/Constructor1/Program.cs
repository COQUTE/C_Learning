using System;

namespace Constructor1
{
    class Person
    {
        string name;
        int id;

        public Person(string name, int id)
        {
            this.name = name;
            this.id = id;
            Console.WriteLine(name + "\n" + id);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person obj = new Person("Michel", 2021);
        }
    }
}
