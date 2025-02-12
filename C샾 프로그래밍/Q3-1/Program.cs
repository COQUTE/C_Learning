using System;

namespace Q3_1
{
    class A
    {
        protected int n1, n2;

        protected void input1()
        {
            Console.Write("input1: ");
            n1 = int.Parse(Console.ReadLine());

            Console.Write("input2: ");
            n2 = int.Parse(Console.ReadLine());
        }
    }

    class B : A
    {
        private int n3, n4;

        public void input2()
        {
            Console.Write("input3: ");
            n3 = int.Parse(Console.ReadLine());

            Console.Write("input4: ");
            n4 = int.Parse(Console.ReadLine());
        }

        public void output()
        {
            Console.WriteLine("n1: " + n1);
            Console.WriteLine("n2: " + n2);
            Console.WriteLine("n3: " + n3);
            Console.WriteLine("n4: " + n4);

            int sum = n1 + n2 + n3 + n4;

            Console.WriteLine("n1 + n2 + n3 + n4: " + sum);
        }

        static void Main(string[] args)
        {
            B obj = new B();

            obj.input1();
            obj.input2();
            obj.output();
        }
    }
}
