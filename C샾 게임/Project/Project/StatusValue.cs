using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project
{
    public class StatusValue
    {
        public static int[][] STAT = {
            new int[4] { 700, 50, 40, 30 },
            new int[4] { 600, 40, 50, 40 },
            new int[4] { 650, 30, 50, 20 },
            new int[4] { 620, 30, 40, 50 }
        };

        public static int[][] MSTAT =
        {
            new int[4] { 620, 40, 30, 40 },
            new int[4] { 600, 50, 20, 40 },
            new int[4] { 650, 30, 50, 10 },
            new int[4] { 1000, 40, 40, 40 }
        };

        public static string[] MNAME = new string[4] { "Skul Warrior", "Skul Wizard", "Big Slime", "Demon King" };
    }
}
