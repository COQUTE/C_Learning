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
    public partial class NamingForm : Form
    {
        public NamingForm()
        {
            InitializeComponent();
        }

        private void namingForm_Load(object sender, EventArgs e)
        {

        }

        private void btnBack_Click(object sender, EventArgs e)
        {
            this.Hide();
            MenuForm startForm = new MenuForm();
            startForm.Show();
            Program.ac.MainForm = startForm;
            this.Close();
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtName.Text))
            {
                MessageBox.Show("Please enter your name");
            }
            else
            {
                Program.player.setName(txtName.Text);

                this.Hide();
                SelectionForm charForm = new SelectionForm();
                charForm.Show();
                Program.ac.MainForm = charForm;
                this.Close();
            }
        }
    }
}
