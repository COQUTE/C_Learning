using System;

namespace Constructor
{
    class A
    {
        string name;
        int phone;
        protected void getdata()
        {
            name = Console.ReadLine();
            phone = int.Parse(Console.ReadLine());
        }
        protected void display()
        {
            Console.WriteLine("Name:" + name);
            Console.WriteLine("Phone:" + phone);
        }
        public A(int a)
        {
            Console.WriteLine("This is parent class constructor:" + a);
        }
    }
    
    // 자녀 class는 new로 생성될 때, 자동적으로 부모 class의 생성자를 호출함.
    class B : A
    {
        int height, weight;
        void getdata1()
        {
            height = int.Parse(Console.ReadLine());
            weight = int.Parse(Console.ReadLine());
        }
        void display1()
        {
            Console.WriteLine("Height:" + height);
            Console.WriteLine("Weigth:" + weight);
        }
        B(int a) : base(a)
        {
            Console.WriteLine("This is child class constructor");
        }

        static void Main(string[] args)
        {
            B obj1 = new B(100);
            obj1.getdata();
            obj1.getdata1();
            obj1.display();
            obj1.display1();
        }
    }
}
