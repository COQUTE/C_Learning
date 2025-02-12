using System;
using System.Collections.Generic;
using System.Text;

namespace Q3_2
{
    class B : A
    {
        private string name;
        private int num;

        public string getName()
        {
            return name;
        }
        public int getNum()
        {
            return num;
        }

        public B()
        {
            Console.Write("Name: ");
            this.name = Console.ReadLine();

            Console.Write("Num: ");
            this.num = int.Parse(Console.ReadLine());

            show(this.name, this.num);
        }

        public void show(string name, int num)
        {
            Console.WriteLine(name + " " + num);
            Console.WriteLine("------------------");
        }
    }
}
