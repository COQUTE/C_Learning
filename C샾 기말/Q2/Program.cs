using System;
using System.IO;

namespace Q2
{
    class Program
    {
        static void Main(string[] args)
        {
            char YN;
            int id;
            string name;
            int age;

            StreamWriter fwrite = new StreamWriter(@"C:\\test\\17011562.txt");

            do
            {
                Console.Write("Enter Id: ");
                id = int.Parse(Console.ReadLine());
                Console.Write("Enter name: ");
                name = Console.ReadLine();
                Console.Write("Enter age: ");
                age = int.Parse(Console.ReadLine());

                Console.WriteLine("------------");
                Console.Write("Do you want to continue? => ");
                YN = char.Parse(Console.ReadLine());

                fwrite.WriteLine("Id: " + id);
                fwrite.WriteLine("Name: " + name);
                fwrite.WriteLine("Age: " + age);
                fwrite.WriteLine("------------");

                if (YN == 'Y' || YN == 'y')
                {
                    continue;
                }
                else if (YN == 'N' || YN == 'n')
                {
                    break;
                }
            } while (true);

            fwrite.Close();
            Console.WriteLine("Data written successfully...");
        }
    }
}
