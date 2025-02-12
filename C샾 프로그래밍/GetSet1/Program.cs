using System;

namespace GetSet1
{
    /*
    class Student
    {
        private string name;
        
        internal Student(string name)
        {
            this.name = name;
        }

        public string getName()
        {
            return name;
        }
        public void setName(string name)
        {
            this.name = name;
        }
    }
    */

    class Student
    {
        string name;

        internal Student(string name)
        {
            this.name = name;
        }

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Student student = new Student("Key");

            student.Name = "NotKey";
            Console.WriteLine("Name:" + student.Name);
        }
    }
}
