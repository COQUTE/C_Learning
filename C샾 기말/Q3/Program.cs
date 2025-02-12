using System;
using System.IO;

namespace Q3
{
    class Program
    {
        static void Main(string[] args)
        {
            string name;
            int id;
            int age;

            StreamWriter fwrite = new StreamWriter(@"C:\\test\\17011562.txt");
            
            Console.Write("Enter your name:");
            name = Console.ReadLine();
            Console.Write("Enter your id:");
            id = int.Parse(Console.ReadLine());
            Console.Write("Enter your Age:");
            age = int.Parse(Console.ReadLine());

            fwrite.WriteLine("NAME:" + name);
            fwrite.WriteLine("ID:" + id);
            fwrite.WriteLine("Age:" + age);

            fwrite.Close();

            StreamReader fread = new StreamReader(@"C:\\test\\17011562.txt");

            string result = fread.ReadToEnd();
            
            Console.WriteLine(result);

            StreamWriter fwrite2 = new StreamWriter(@"C:\\test\\copy.txt");
            fwrite2.WriteLine(result);

            fread.Close();
            fwrite2.Close();
        }
    }
}
