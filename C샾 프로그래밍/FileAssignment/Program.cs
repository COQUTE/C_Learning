using System;
using System.IO;

namespace FileAssignment
{
    class ReadWriteInfo
    {
        private string name;
        private int id;
        private int age;

        public void input()
        {
            Console.Write("Enter your name:");
            name = Console.ReadLine();
            Console.Write("Enter your id:");
            id = int.Parse(Console.ReadLine());
            Console.Write("Enter your Age:");
            age = int.Parse(Console.ReadLine());
        }
        
        public void fileWrite()
        {
            StreamWriter fWrite = new StreamWriter(@"C:\file\file.txt");
            fWrite.WriteLine("NAME:" + name);
            fWrite.WriteLine("ID:" + id);
            fWrite.WriteLine("Age:" + age);
            fWrite.Close();
        }

        public void fileRead()
        {
            string txt;

            StreamReader fRead = new StreamReader(@"C:\file\file.txt");
            txt = fRead.ReadToEnd();
            Console.WriteLine(txt);
            fRead.Close();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ReadWriteInfo c = new ReadWriteInfo();

            c.input();
            c.fileWrite();
            c.fileRead();
        }
    }
}
