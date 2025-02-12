using System;

namespace Polymorphism_and_Interface
{
    class Parent
    {
        int n1, n2;

        public Parent()
        {
            Console.WriteLine("Default Constructor");
        }
        public Parent(int a, int b)
        {
            n1 = a;
            n2 = b;
            Console.WriteLine("Parameterized Constructor");
            Console.WriteLine("Invoked value: " + n1 + " and " + n2);
        }

        public virtual void output()
        {
            Console.WriteLine("Parent Class");
        }
    }

    // sealed 식별자를 쓰면 계승 X, override X 하지만 자녀 class의 override method는 sealed 사용가능

    class Child : Parent
    {
        public Child() : base()
        {

        }

        public Child(int i, int j) : base(i, j)
        {

        }

        sealed public override void output()
        {
            base.output();
            Console.WriteLine("Child Class");
        }

        static void Main(string[] args)
        {
            Child obj = new Child();
            obj.output();

            Child obj1 = new Child(1, 2);
        }
    }
}
