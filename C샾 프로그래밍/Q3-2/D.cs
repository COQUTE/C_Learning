using System;
using System.Collections.Generic;
using System.Text;

namespace Q3_2
{
    class D : B, C
    {
        D() : base()
        {

        }

        public void match(string name, int num)
        {
            if (getName() == name && getNum() == num)
            {
                Console.WriteLine("Same!");
            }
            else
            {
                Console.WriteLine("Not same!");
            }
        }

        static void Main(string[] args)
        {
            D obj = new D();

            string name;
            int num;

            Console.Write("Your name: ");
            name = Console.ReadLine();

            Console.Write("Your num: ");
            num = int.Parse(Console.ReadLine());

            obj.show(name, num);

            obj.match(name, num);
        }
    }
}
