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
    public partial class SelectionForm : Form
    {
        public SelectionForm()
        {
            InitializeComponent();
        }

        private void selectionForm_Load(object sender, EventArgs e)
        {

        }

        private void btnBack_Click(object sender, EventArgs e)
        {
            this.Hide();
            NamingForm nameForm = new NamingForm();
            nameForm.Show();
            Program.ac.MainForm = nameForm;
            this.Close();
        }

        private void btnSelect_Click(object sender, EventArgs e)
        {
            if (btnC1.Checked) { Program.player.setJob(Job.Warrior); }
            if (btnC2.Checked) { Program.player.setJob(Job.Wizard); }
            if (btnC3.Checked) { Program.player.setJob(Job.Knight); }
            if (btnC4.Checked) { Program.player.setJob(Job.Archor); }

            this.Hide();
            ProfileForm userForm = new ProfileForm();
            userForm.Show();
            Program.ac.MainForm = userForm;
            this.Close();
        }

        private void picC1_Click(object sender, EventArgs e)
        {
            btnC1.Checked = true;
        }

        private void picC2_Click(object sender, EventArgs e)
        {
            btnC2.Checked = true;
        }

        private void picC3_Click(object sender, EventArgs e)
        {
            btnC3.Checked = true;
        }

        private void picC4_Click(object sender, EventArgs e)
        {
            btnC4.Checked = true;
        }
    }
}
