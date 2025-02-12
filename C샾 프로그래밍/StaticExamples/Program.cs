using System;

namespace StaticExamples
{
    class Stu
    {
        static int id;
    }

    class Program
    {
        static string name;
        static int age;

        static void input(string _name, int _age)
        {
            name = _name;
            age = _age;
        }

        static void Main(string[] args)
        {
            input("Michel", 14);
            Console.WriteLine(name + "\n" + age);
        }
    }
}
