using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project
{
    enum Job  { Warrior, Wizard, Knight, Archor }
    enum Type { SkulWarrior, SkulWizard, Slime, Boss }

    static class Program
    {
        public static ApplicationContext ac = new ApplicationContext();
        public static Player player;

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            player = new Player();

            MenuForm startForm = new MenuForm();
            ac.MainForm = startForm;
            Application.Run(ac);
        }
    }
}
