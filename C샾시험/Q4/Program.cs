using System;

namespace Q4
{
    class Person
    {
        static string name;
        static int id;
        static double BodyTemperature;

        public static void getdata()
        {
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Id: " + id);

            string canBoard = BodyTemperature > 37.2 ? "Sorry, you can't board" : "you can board";
            Console.WriteLine(canBoard);
        }

        public static void putdata()
        {
            Console.Write("Name: ");
            name = Console.ReadLine();
            Console.Write("Id: ");
            id = int.Parse(Console.ReadLine());
            Console.Write("Body Temperature: ");
            BodyTemperature = double.Parse(Console.ReadLine());
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person.putdata();
            Person.getdata();
        }
    }
}
