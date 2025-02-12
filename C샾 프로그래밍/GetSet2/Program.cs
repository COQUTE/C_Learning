using System;

namespace GetSet2
{
    class Program
    {
        static void Main(string[] args)
        {
            Account myAccount = new Account();

            Console.WriteLine($"Initial name is: {myAccount.Name}");

            Console.Write("Please enter the name: ");
            string theName = Console.ReadLine();
            myAccount.Name = theName;

            Console.WriteLine($"myAccount's name is: {myAccount.Name}");
        }
    }
}
