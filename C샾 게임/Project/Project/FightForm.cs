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
    public partial class FightForm : Form
    {
        private List<Monster> _monsters;

        private Random _random;
        private int _rNum;

        private int _leftMonster;

        private int _playerTmpHP;
        private int _monsterTmpHP;

        public FightForm()
        {
            InitializeComponent();

            playerProfile();

            btnAttack.Visible = false;
            btnSkill.Visible  = false;
            btnHeal.Visible   = false;

            _monsters = new List<Monster>();
            Type type = Type.SkulWarrior;
            for (int i = 0; i < 4; i++)
            {
                _monsters.Add(new Monster(type));
                type++;
            }

            _random = new Random();
            _rNum = _random.Next(3);

            _leftMonster = 4;
            lblNumber.Text = Convert.ToString(_leftMonster);
        }

        public void playerProfile()
        {
            if (Program.player.getJob() != Job.Warrior) { picC1.Visible = false; }
            if (Program.player.getJob() != Job.Wizard)  { picC2.Visible = false; }
            if (Program.player.getJob() != Job.Knight)  { picC3.Visible = false; }
            if (Program.player.getJob() != Job.Archor)  { picC4.Visible = false; }

            _playerTmpHP = Program.player.getStatus().getHP();

            Job job = Program.player.getJob();
            switch (job)
            {
                case Job.Warrior:
                    groupPlayerStatus.Text = "Warrior";
                    break;
                case Job.Wizard:
                    groupPlayerStatus.Text = "Wizard";
                    break;
                case Job.Knight:
                    groupPlayerStatus.Text = "Knight";
                    break;
                case Job.Archor:
                    groupPlayerStatus.Text = "Archor";
                    break;
            }

            lblPlayerHP.Text  = Convert.ToString(Program.player.getStatus().getHP());
            lblPlayerATK.Text = Convert.ToString(Program.player.getStatus().getATK());
            lblPlayerDEF.Text = Convert.ToString(Program.player.getStatus().getDEF());
            lblPlayerSPD.Text = Convert.ToString(Program.player.getStatus().getSPD());
        }

        public void randomMonsterProfile()
        {
            picM1.Visible = false;
            picM2.Visible = false;
            picM3.Visible = false;
            picM4.Visible = false;

            _rNum = (_rNum + _random.Next(1, 3)) % 3;

            Monster monster = _monsters[_rNum];

            if (monster.getType() == Type.SkulWarrior) { picM1.Visible = true; }
            if (monster.getType() == Type.SkulWizard)  { picM2.Visible = true; }
            if (monster.getType() == Type.Slime)       { picM3.Visible = true; }

            _monsterTmpHP = monster.getStatus().getHP();

            Type type = monster.getType();
            switch (type)
            {
                case Type.SkulWarrior:
                    groupMonsterStatus.Text = "Skul Warrior";
                    break;
                case Type.SkulWizard:
                    groupMonsterStatus.Text = "Skul Wizard";
                    break;
                case Type.Slime:
                    groupMonsterStatus.Text = "Big Slime";
                    break;
            }

            lblMonsterHP.Text  = Convert.ToString(monster.getStatus().getHP());
            lblMonsterATK.Text = Convert.ToString(monster.getStatus().getATK());
            lblMonsterDEF.Text = Convert.ToString(monster.getStatus().getDEF());
            lblMonsterSPD.Text = Convert.ToString(monster.getStatus().getSPD());
        }

        public void bossProfile()
        {
            lblLeftMonster.Text = "---- Boss Stage ----";
            lblNumber.Visible = false;

            picM1.Visible = false;
            picM2.Visible = false;
            picM3.Visible = false;
            picM4.Visible = true;

            Monster monster = _monsters[(int)Type.Boss];

            _monsterTmpHP = monster.getStatus().getHP();

            groupMonsterStatus.Text = "Demon King";
            lblMonsterHP.Text = Convert.ToString(monster.getStatus().getHP());
            lblMonsterATK.Text = Convert.ToString(monster.getStatus().getATK());
            lblMonsterDEF.Text = Convert.ToString(monster.getStatus().getDEF());
            lblMonsterSPD.Text = Convert.ToString(monster.getStatus().getSPD());
        }

        public void updatePHP() { lblPlayerHP.Text  = Convert.ToString(_playerTmpHP); }
        public void updateMHP() { lblMonsterHP.Text = Convert.ToString(_monsterTmpHP); }
        public void updateBothHP()
        {
            updatePHP();
            updateMHP();
        }

        public void damageCheck(ref int playerTmpHP, ref int monsterTmpHP, bool skill)
        {
            Monster monster = _monsters[_rNum];

            if (skill == false)
            {
                playerTmpHP  -= monster.trueDamage(Program.player.getStatus().getDEF());
                monsterTmpHP -= Program.player.trueDamage(monster.getStatus().getSPD(), monster.getStatus().getDEF());

                updateBothHP();
            }
            else
            {
                monsterTmpHP -= 100;

                updateMHP();
            }
        }
        public void resultCheck(ref int playerTmpHP, ref int monsterTmpHP)
        {
            bool win = new bool();

            if (_monsterTmpHP <= 0 || _playerTmpHP <= 0) // win or lose
            {
                if (_playerTmpHP <= 0)
                    win = false; // lose
                else if (_monsterTmpHP <= 0)
                    win = true; // win

                playerTmpHP  = Program.player.getStatus().getHP();
                monsterTmpHP = _monsters[_rNum].getStatus().getHP();

                updateBothHP();

                if (win)
                {
                    if (_leftMonster == 0) // boss stage
                    {
                        this.Hide();
                        GameResultForm resultForm = new GameResultForm(true);
                        resultForm.Show();
                        Program.ac.MainForm = resultForm;
                        this.Close();
                    }

                    btnAttack.Visible = false;
                    btnSkill.Visible = false;
                    btnHeal.Visible = false;

                    btnRun.Visible = true;
                    btnFight.Visible = true;

                    _leftMonster--;
                    if (_leftMonster != 0)
                    {
                        lblNumber.Text = Convert.ToString(_leftMonster);

                        randomMonsterProfile();
                    }
                    else
                    {
                        bossProfile();

                        btnRun.Enabled = false;
                    }
                }
                else
                {
                    this.Hide();
                    GameResultForm resultForm = new GameResultForm(false);
                    resultForm.Show();
                    Program.ac.MainForm = resultForm;
                    this.Close();
                }
            }
        }

        public void heal(ref int playerTmpHP, int value)
        {
            playerTmpHP += value;
            updatePHP();
        }

        private void FightForm_Load(object sender, EventArgs e)
        {
            randomMonsterProfile();
        }

        private void btnRun_Click(object sender, EventArgs e)
        {
            randomMonsterProfile();
        }

        private void btnFight_Click(object sender, EventArgs e)
        {
            btnRun.Visible   = false;
            btnFight.Visible = false;

            btnAttack.Visible = true;
            btnSkill.Visible  = true;
            btnHeal.Visible   = true;
        }

        private void btnAttack_Click(object sender, EventArgs e)
        {
            damageCheck(ref _playerTmpHP, ref _monsterTmpHP, false); // false : normal attack
            resultCheck(ref _playerTmpHP, ref _monsterTmpHP);
        }

        private void btnSkill_Click(object sender, EventArgs e)
        {
            btnSkill.Visible = false;

            int rSkill = _random.Next(2);

            if (rSkill == 0)
            {
                damageCheck(ref _playerTmpHP, ref _monsterTmpHP, true); // true : skill attack
                resultCheck(ref _playerTmpHP, ref _monsterTmpHP);
            }
            else if (rSkill == 1)
            {
                heal(ref _playerTmpHP, 200);
            }
        }

        private void btnHeal_Click(object sender, EventArgs e)
        {
            btnHeal.Visible = false;
            heal(ref _playerTmpHP, 50);
        }
    }
}
