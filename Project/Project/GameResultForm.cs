using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project
{
    public partial class GameResultForm : Form
    {
        public GameResultForm(bool win)
        {
            InitializeComponent();

            if (win)
                lblResult.Text = "You Win !";
            else
                lblResult.Text = "You Lose...";
        }

        private void btnTitle_Click(object sender, EventArgs e)
        {
            this.Hide();
            MenuForm startForm = new MenuForm();
            startForm.Show();
            Program.ac.MainForm = startForm;
            this.Close();
        }

        private void btnEnd_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void GameResultForm_Load(object sender, EventArgs e)
        {

        }
    }
}
