using System;

namespace Six_Sided_Die
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rNum = new Random();

            int n1 = 0;
            int n2 = 0;
            int n3 = 0;
            int n4 = 0;
            int n5 = 0;
            int n6 = 0;

            for (int i = 0; i < 60000000; i++)
            {
                int dot = rNum.Next(1, 7);
                
                switch(dot)
                {
                    case 1:
                        n1++;
                        break;
                    case 2:
                        n2++;
                        break;
                    case 3:
                        n3++;
                        break;
                    case 4:
                        n4++;
                        break;
                    case 5:
                        n5++;
                        break;
                    case 6:
                        n6++;
                        break;
                }
            }
            Console.Write(n1 + "\n" + n2 + "\n" + n3 + "\n" + n4 + "\n" + n5 + "\n" + n6 + "\n");
        }
    }
}
