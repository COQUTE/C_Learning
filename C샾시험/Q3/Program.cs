using System;

namespace Q3
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int line = 0; line < 4; line++)
            {
                for (int blank = 3; blank >= line; blank--)
                {
                    Console.Write(" ");
                }

                for (int star = 1; star <= 2 * line + 1; star++)
                {
                    Console.Write("*");
                }

                Console.WriteLine();
            }

            for (int line = 4; line >= 0; line--)
            {
                for (int blank = 4; blank > line; blank--)
                {
                    Console.Write(" ");
                }

                for (int star = line * 2 + 1; star > 0; star--)
                {
                    Console.Write("*");
                }

                Console.WriteLine();
            }
        }
    }
}
