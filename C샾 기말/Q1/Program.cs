using System;

namespace Q1
{
    class A
    {
        public int n1, n2;
        public A()
        {
            Random random = new Random();

            n1 = random.Next(100);
            n2 = random.Next(100);
        }
    }
    class B : A
    {
        int n3, n4;

        public void input()
        {
            Console.WriteLine("Enter other two numbers");
            n3 = int.Parse(Console.ReadLine());
            n4 = int.Parse(Console.ReadLine());
        }
        public void output()
        {
            Console.WriteLine("Two random numbers");

            Console.WriteLine(n1);
            Console.WriteLine(n2);

            input();

            Console.WriteLine("Addition: " + (n1 + n2 + n3 + n4));
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            B child = new B();

            child.output();
        }
    }
}
