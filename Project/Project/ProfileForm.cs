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
    public partial class ProfileForm : Form
    {
        public ProfileForm()
        {
            InitializeComponent();

            InitProfile();
        }

        private void InitProfile()
        {
            if (Program.player.getJob() != Job.Warrior) { picC1.Visible = false; }
            if (Program.player.getJob() != Job.Wizard) { picC2.Visible = false; }
            if (Program.player.getJob() != Job.Knight) { picC3.Visible = false; }
            if (Program.player.getJob() != Job.Archor) { picC4.Visible = false; }

            lblPlayerName.Text = Program.player.getName();

            Job job = Program.player.getJob();
            switch (job)
            {
                case Job.Warrior:
                    lblPlayerCharacter.Text = "Warrior";
                    break;
                case Job.Wizard:
                    lblPlayerCharacter.Text = "Wizard";
                    break;
                case Job.Knight:
                    lblPlayerCharacter.Text = "Knight";
                    break;
                case Job.Archor:
                    lblPlayerCharacter.Text = "Archor";
                    break;
            }

            lblPlayerHP.Text = Convert.ToString(Program.player.getStatus().getHP());
            lblPlayerATK.Text = Convert.ToString(Program.player.getStatus().getATK());
            lblPlayerDEF.Text = Convert.ToString(Program.player.getStatus().getDEF());
            lblPlayerSPD.Text = Convert.ToString(Program.player.getStatus().getSPD());
        }

        private void ProfileForm_Load(object sender, EventArgs e)
        {
            
        }

        private void btnBack_Click(object sender, EventArgs e)
        {
            this.Hide();
            SelectionForm charForm = new SelectionForm();
            charForm.Show();
            Program.ac.MainForm = charForm;
            this.Close();
        }

        private void btnFinish_Click(object sender, EventArgs e)
        {
            this.Hide();
            FightForm fightForm = new FightForm();
            fightForm.Show();
            Program.ac.MainForm = fightForm;
            this.Close();
        }
    }
}
