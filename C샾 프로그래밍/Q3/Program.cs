using System;

namespace Q3
{
    class Program
    {
        // I used method overriding (MaxMinOfFour) & static type to use these methods directly without creating object
        public static void MaxMinOfFour(int a, int b, int c, int d)
        {
            // I compared result of comparing n1 with n2 and n3 with n4
            int max;

            max = (((a >= b) ? a : b) >= ((c >= d) ? c : d)) ? ((a >= b) ? a : b) : ((c >= d) ? c : d);

            int min;

            min = (((a <= b) ? a : b) <= ((c <= d) ? c : d)) ? ((a <= b) ? a : b) : ((c <= d) ? c : d);

            Console.WriteLine("Largest of four : " + max);
            Console.WriteLine("Smallest of four : " + min);
        }
        public static void MaxMinOfFour(double a, double b, double c, double d)
        {
            // I compared result of comparing n1 with n2 and n3 with n4
            double max;

            max = (((a >= b) ? a : b) >= ((c >= d) ? c : d)) ? ((a >= b) ? a : b) : ((c >= d) ? c : d);

            double min;

            min = (((a <= b) ? a : b) <= ((c <= d) ? c : d)) ? ((a <= b) ? a : b) : ((c <= d) ? c : d);

            Console.WriteLine("Largest of four : " + max);
            Console.WriteLine("Smallest of four : " + min);
        }

        static void Main(string[] args)
        {
            Console.Write("Input:");

            int input = int.Parse(Console.ReadLine());

            if (input == 1)
            {
                int n1 = int.Parse(Console.ReadLine());
                int n2 = int.Parse(Console.ReadLine());
                int n3 = int.Parse(Console.ReadLine());
                int n4 = int.Parse(Console.ReadLine());

                MaxMinOfFour(n1, n2, n3, n4);
            }
            else // input == 2
            {
                double m1 = double.Parse(Console.ReadLine());
                double m2 = double.Parse(Console.ReadLine());
                double m3 = double.Parse(Console.ReadLine());
                double m4 = double.Parse(Console.ReadLine());

                MaxMinOfFour(m1, m2, m3, m4);
            }
        }
    }
}
