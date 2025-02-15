
namespace Project
{
    partial class FightForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FightForm));
            this.picC4 = new System.Windows.Forms.PictureBox();
            this.picC3 = new System.Windows.Forms.PictureBox();
            this.picC2 = new System.Windows.Forms.PictureBox();
            this.picC1 = new System.Windows.Forms.PictureBox();
            this.groupPlayerStatus = new System.Windows.Forms.GroupBox();
            this.lblLeftSPD = new System.Windows.Forms.Label();
            this.lblLeftDEF = new System.Windows.Forms.Label();
            this.lblLeftATK = new System.Windows.Forms.Label();
            this.lblLeftHP = new System.Windows.Forms.Label();
            this.lblPlayerSPD = new System.Windows.Forms.Label();
            this.lblPlayerDEF = new System.Windows.Forms.Label();
            this.lblPlayerATK = new System.Windows.Forms.Label();
            this.lblPlayerHP = new System.Windows.Forms.Label();
            this.groupMonsterStatus = new System.Windows.Forms.GroupBox();
            this.lblRightSPD = new System.Windows.Forms.Label();
            this.lblRightDEF = new System.Windows.Forms.Label();
            this.lblRightATK = new System.Windows.Forms.Label();
            this.lblRightHP = new System.Windows.Forms.Label();
            this.lblMonsterSPD = new System.Windows.Forms.Label();
            this.lblMonsterDEF = new System.Windows.Forms.Label();
            this.lblMonsterATK = new System.Windows.Forms.Label();
            this.lblMonsterHP = new System.Windows.Forms.Label();
            this.picM4 = new System.Windows.Forms.PictureBox();
            this.picM1 = new System.Windows.Forms.PictureBox();
            this.picM2 = new System.Windows.Forms.PictureBox();
            this.picM3 = new System.Windows.Forms.PictureBox();
            this.lblVersus = new System.Windows.Forms.Label();
            this.btnFight = new System.Windows.Forms.Button();
            this.btnRun = new System.Windows.Forms.Button();
            this.btnAttack = new System.Windows.Forms.Button();
            this.btnSkill = new System.Windows.Forms.Button();
            this.btnHeal = new System.Windows.Forms.Button();
            this.lblLeftMonster = new System.Windows.Forms.Label();
            this.lblNumber = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.picC4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC1)).BeginInit();
            this.groupPlayerStatus.SuspendLayout();
            this.groupMonsterStatus.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picM4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picM1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picM2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picM3)).BeginInit();
            this.SuspendLayout();
            // 
            // picC4
            // 
            this.picC4.BackColor = System.Drawing.Color.Transparent;
            this.picC4.Image = ((System.Drawing.Image)(resources.GetObject("picC4.Image")));
            this.picC4.Location = new System.Drawing.Point(154, 29);
            this.picC4.Name = "picC4";
            this.picC4.Size = new System.Drawing.Size(240, 370);
            this.picC4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picC4.TabIndex = 17;
            this.picC4.TabStop = false;
            // 
            // picC3
            // 
            this.picC3.BackColor = System.Drawing.Color.Transparent;
            this.picC3.Image = ((System.Drawing.Image)(resources.GetObject("picC3.Image")));
            this.picC3.Location = new System.Drawing.Point(144, 29);
            this.picC3.Name = "picC3";
            this.picC3.Size = new System.Drawing.Size(260, 370);
            this.picC3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picC3.TabIndex = 16;
            this.picC3.TabStop = false;
            // 
            // picC2
            // 
            this.picC2.BackColor = System.Drawing.Color.Transparent;
            this.picC2.Image = ((System.Drawing.Image)(resources.GetObject("picC2.Image")));
            this.picC2.Location = new System.Drawing.Point(144, 29);
            this.picC2.Name = "picC2";
            this.picC2.Size = new System.Drawing.Size(260, 370);
            this.picC2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picC2.TabIndex = 15;
            this.picC2.TabStop = false;
            // 
            // picC1
            // 
            this.picC1.BackColor = System.Drawing.Color.Transparent;
            this.picC1.Image = ((System.Drawing.Image)(resources.GetObject("picC1.Image")));
            this.picC1.Location = new System.Drawing.Point(82, 29);
            this.picC1.Name = "picC1";
            this.picC1.Size = new System.Drawing.Size(380, 370);
            this.picC1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picC1.TabIndex = 14;
            this.picC1.TabStop = false;
            // 
            // groupPlayerStatus
            // 
            this.groupPlayerStatus.BackColor = System.Drawing.Color.Transparent;
            this.groupPlayerStatus.Controls.Add(this.lblLeftSPD);
            this.groupPlayerStatus.Controls.Add(this.lblLeftDEF);
            this.groupPlayerStatus.Controls.Add(this.lblLeftATK);
            this.groupPlayerStatus.Controls.Add(this.lblLeftHP);
            this.groupPlayerStatus.Controls.Add(this.lblPlayerSPD);
            this.groupPlayerStatus.Controls.Add(this.lblPlayerDEF);
            this.groupPlayerStatus.Controls.Add(this.lblPlayerATK);
            this.groupPlayerStatus.Controls.Add(this.lblPlayerHP);
            this.groupPlayerStatus.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.groupPlayerStatus.Location = new System.Drawing.Point(87, 440);
            this.groupPlayerStatus.Name = "groupPlayerStatus";
            this.groupPlayerStatus.Size = new System.Drawing.Size(370, 320);
            this.groupPlayerStatus.TabIndex = 13;
            this.groupPlayerStatus.TabStop = false;
            this.groupPlayerStatus.Text = "Status";
            // 
            // lblLeftSPD
            // 
            this.lblLeftSPD.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblLeftSPD.Location = new System.Drawing.Point(60, 240);
            this.lblLeftSPD.Name = "lblLeftSPD";
            this.lblLeftSPD.Size = new System.Drawing.Size(120, 40);
            this.lblLeftSPD.TabIndex = 4;
            this.lblLeftSPD.Text = "SPD:";
            this.lblLeftSPD.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblLeftDEF
            // 
            this.lblLeftDEF.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblLeftDEF.Location = new System.Drawing.Point(60, 180);
            this.lblLeftDEF.Name = "lblLeftDEF";
            this.lblLeftDEF.Size = new System.Drawing.Size(120, 40);
            this.lblLeftDEF.TabIndex = 4;
            this.lblLeftDEF.Text = "DEF:";
            this.lblLeftDEF.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblLeftATK
            // 
            this.lblLeftATK.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblLeftATK.Location = new System.Drawing.Point(60, 120);
            this.lblLeftATK.Name = "lblLeftATK";
            this.lblLeftATK.Size = new System.Drawing.Size(120, 40);
            this.lblLeftATK.TabIndex = 4;
            this.lblLeftATK.Text = "ATK:";
            this.lblLeftATK.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblLeftHP
            // 
            this.lblLeftHP.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblLeftHP.Location = new System.Drawing.Point(60, 60);
            this.lblLeftHP.Name = "lblLeftHP";
            this.lblLeftHP.Size = new System.Drawing.Size(120, 40);
            this.lblLeftHP.TabIndex = 4;
            this.lblLeftHP.Text = "HP:";
            this.lblLeftHP.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblPlayerSPD
            // 
            this.lblPlayerSPD.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.lblPlayerSPD.Location = new System.Drawing.Point(200, 240);
            this.lblPlayerSPD.Name = "lblPlayerSPD";
            this.lblPlayerSPD.Size = new System.Drawing.Size(148, 40);
            this.lblPlayerSPD.TabIndex = 8;
            this.lblPlayerSPD.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblPlayerDEF
            // 
            this.lblPlayerDEF.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.lblPlayerDEF.Location = new System.Drawing.Point(200, 180);
            this.lblPlayerDEF.Name = "lblPlayerDEF";
            this.lblPlayerDEF.Size = new System.Drawing.Size(148, 40);
            this.lblPlayerDEF.TabIndex = 8;
            this.lblPlayerDEF.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblPlayerATK
            // 
            this.lblPlayerATK.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.lblPlayerATK.Location = new System.Drawing.Point(200, 120);
            this.lblPlayerATK.Name = "lblPlayerATK";
            this.lblPlayerATK.Size = new System.Drawing.Size(148, 40);
            this.lblPlayerATK.TabIndex = 8;
            this.lblPlayerATK.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblPlayerHP
            // 
            this.lblPlayerHP.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.lblPlayerHP.Location = new System.Drawing.Point(200, 60);
            this.lblPlayerHP.Name = "lblPlayerHP";
            this.lblPlayerHP.Size = new System.Drawing.Size(148, 40);
            this.lblPlayerHP.TabIndex = 8;
            this.lblPlayerHP.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // groupMonsterStatus
            // 
            this.groupMonsterStatus.BackColor = System.Drawing.Color.Transparent;
            this.groupMonsterStatus.Controls.Add(this.lblRightSPD);
            this.groupMonsterStatus.Controls.Add(this.lblRightDEF);
            this.groupMonsterStatus.Controls.Add(this.lblRightATK);
            this.groupMonsterStatus.Controls.Add(this.lblRightHP);
            this.groupMonsterStatus.Controls.Add(this.lblMonsterSPD);
            this.groupMonsterStatus.Controls.Add(this.lblMonsterDEF);
            this.groupMonsterStatus.Controls.Add(this.lblMonsterATK);
            this.groupMonsterStatus.Controls.Add(this.lblMonsterHP);
            this.groupMonsterStatus.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.groupMonsterStatus.Location = new System.Drawing.Point(711, 440);
            this.groupMonsterStatus.Name = "groupMonsterStatus";
            this.groupMonsterStatus.Size = new System.Drawing.Size(370, 320);
            this.groupMonsterStatus.TabIndex = 13;
            this.groupMonsterStatus.TabStop = false;
            this.groupMonsterStatus.Text = "Status";
            // 
            // lblRightSPD
            // 
            this.lblRightSPD.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblRightSPD.Location = new System.Drawing.Point(60, 240);
            this.lblRightSPD.Name = "lblRightSPD";
            this.lblRightSPD.Size = new System.Drawing.Size(120, 40);
            this.lblRightSPD.TabIndex = 4;
            this.lblRightSPD.Text = "SPD:";
            this.lblRightSPD.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblRightDEF
            // 
            this.lblRightDEF.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblRightDEF.Location = new System.Drawing.Point(60, 180);
            this.lblRightDEF.Name = "lblRightDEF";
            this.lblRightDEF.Size = new System.Drawing.Size(120, 40);
            this.lblRightDEF.TabIndex = 4;
            this.lblRightDEF.Text = "DEF:";
            this.lblRightDEF.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblRightATK
            // 
            this.lblRightATK.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblRightATK.Location = new System.Drawing.Point(60, 120);
            this.lblRightATK.Name = "lblRightATK";
            this.lblRightATK.Size = new System.Drawing.Size(120, 40);
            this.lblRightATK.TabIndex = 4;
            this.lblRightATK.Text = "ATK:";
            this.lblRightATK.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblRightHP
            // 
            this.lblRightHP.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblRightHP.Location = new System.Drawing.Point(60, 60);
            this.lblRightHP.Name = "lblRightHP";
            this.lblRightHP.Size = new System.Drawing.Size(120, 40);
            this.lblRightHP.TabIndex = 4;
            this.lblRightHP.Text = "HP:";
            this.lblRightHP.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblMonsterSPD
            // 
            this.lblMonsterSPD.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.lblMonsterSPD.Location = new System.Drawing.Point(200, 240);
            this.lblMonsterSPD.Name = "lblMonsterSPD";
            this.lblMonsterSPD.Size = new System.Drawing.Size(148, 40);
            this.lblMonsterSPD.TabIndex = 8;
            this.lblMonsterSPD.Text = "???";
            this.lblMonsterSPD.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblMonsterDEF
            // 
            this.lblMonsterDEF.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.lblMonsterDEF.Location = new System.Drawing.Point(200, 180);
            this.lblMonsterDEF.Name = "lblMonsterDEF";
            this.lblMonsterDEF.Size = new System.Drawing.Size(148, 40);
            this.lblMonsterDEF.TabIndex = 8;
            this.lblMonsterDEF.Text = "???";
            this.lblMonsterDEF.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblMonsterATK
            // 
            this.lblMonsterATK.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.lblMonsterATK.Location = new System.Drawing.Point(200, 120);
            this.lblMonsterATK.Name = "lblMonsterATK";
            this.lblMonsterATK.Size = new System.Drawing.Size(148, 40);
            this.lblMonsterATK.TabIndex = 8;
            this.lblMonsterATK.Text = "???";
            this.lblMonsterATK.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblMonsterHP
            // 
            this.lblMonsterHP.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.lblMonsterHP.Location = new System.Drawing.Point(200, 60);
            this.lblMonsterHP.Name = "lblMonsterHP";
            this.lblMonsterHP.Size = new System.Drawing.Size(148, 40);
            this.lblMonsterHP.TabIndex = 8;
            this.lblMonsterHP.Text = "???";
            this.lblMonsterHP.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // picM4
            // 
            this.picM4.BackColor = System.Drawing.Color.Transparent;
            this.picM4.Image = ((System.Drawing.Image)(resources.GetObject("picM4.Image")));
            this.picM4.Location = new System.Drawing.Point(693, 15);
            this.picM4.Name = "picM4";
            this.picM4.Size = new System.Drawing.Size(397, 405);
            this.picM4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picM4.TabIndex = 14;
            this.picM4.TabStop = false;
            // 
            // picM1
            // 
            this.picM1.BackColor = System.Drawing.Color.Transparent;
            this.picM1.Image = ((System.Drawing.Image)(resources.GetObject("picM1.Image")));
            this.picM1.Location = new System.Drawing.Point(768, 29);
            this.picM1.Name = "picM1";
            this.picM1.Size = new System.Drawing.Size(260, 370);
            this.picM1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picM1.TabIndex = 15;
            this.picM1.TabStop = false;
            // 
            // picM2
            // 
            this.picM2.BackColor = System.Drawing.Color.Transparent;
            this.picM2.Image = ((System.Drawing.Image)(resources.GetObject("picM2.Image")));
            this.picM2.Location = new System.Drawing.Point(768, 29);
            this.picM2.Name = "picM2";
            this.picM2.Size = new System.Drawing.Size(260, 370);
            this.picM2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picM2.TabIndex = 16;
            this.picM2.TabStop = false;
            // 
            // picM3
            // 
            this.picM3.BackColor = System.Drawing.Color.Transparent;
            this.picM3.Image = ((System.Drawing.Image)(resources.GetObject("picM3.Image")));
            this.picM3.Location = new System.Drawing.Point(778, 29);
            this.picM3.Name = "picM3";
            this.picM3.Size = new System.Drawing.Size(240, 370);
            this.picM3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picM3.TabIndex = 17;
            this.picM3.TabStop = false;
            // 
            // lblVersus
            // 
            this.lblVersus.BackColor = System.Drawing.Color.Transparent;
            this.lblVersus.Font = new System.Drawing.Font("Cooper Black", 32F);
            this.lblVersus.ForeColor = System.Drawing.Color.Red;
            this.lblVersus.Location = new System.Drawing.Point(493, 144);
            this.lblVersus.Name = "lblVersus";
            this.lblVersus.Size = new System.Drawing.Size(181, 124);
            this.lblVersus.TabIndex = 18;
            this.lblVersus.Text = "VS";
            this.lblVersus.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnFight
            // 
            this.btnFight.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnFight.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnFight.FlatAppearance.BorderSize = 0;
            this.btnFight.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnFight.Font = new System.Drawing.Font("Cooper Black", 9F);
            this.btnFight.Location = new System.Drawing.Point(598, 262);
            this.btnFight.Name = "btnFight";
            this.btnFight.Size = new System.Drawing.Size(100, 40);
            this.btnFight.TabIndex = 20;
            this.btnFight.Text = "Fight!";
            this.btnFight.UseVisualStyleBackColor = false;
            this.btnFight.Click += new System.EventHandler(this.btnFight_Click);
            // 
            // btnRun
            // 
            this.btnRun.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnRun.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnRun.FlatAppearance.BorderSize = 0;
            this.btnRun.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnRun.Font = new System.Drawing.Font("Cooper Black", 9F);
            this.btnRun.Location = new System.Drawing.Point(470, 262);
            this.btnRun.Name = "btnRun";
            this.btnRun.Size = new System.Drawing.Size(100, 40);
            this.btnRun.TabIndex = 19;
            this.btnRun.Text = "Run !";
            this.btnRun.UseVisualStyleBackColor = false;
            this.btnRun.Click += new System.EventHandler(this.btnRun_Click);
            // 
            // btnAttack
            // 
            this.btnAttack.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnAttack.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnAttack.FlatAppearance.BorderSize = 0;
            this.btnAttack.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnAttack.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.btnAttack.Location = new System.Drawing.Point(504, 500);
            this.btnAttack.Name = "btnAttack";
            this.btnAttack.Size = new System.Drawing.Size(160, 40);
            this.btnAttack.TabIndex = 21;
            this.btnAttack.Text = "Attack";
            this.btnAttack.UseVisualStyleBackColor = false;
            this.btnAttack.Click += new System.EventHandler(this.btnAttack_Click);
            // 
            // btnSkill
            // 
            this.btnSkill.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnSkill.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnSkill.FlatAppearance.BorderSize = 0;
            this.btnSkill.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSkill.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.btnSkill.Location = new System.Drawing.Point(504, 560);
            this.btnSkill.Name = "btnSkill";
            this.btnSkill.Size = new System.Drawing.Size(160, 40);
            this.btnSkill.TabIndex = 21;
            this.btnSkill.Text = "Skill (1)";
            this.btnSkill.UseVisualStyleBackColor = false;
            this.btnSkill.Click += new System.EventHandler(this.btnSkill_Click);
            // 
            // btnHeal
            // 
            this.btnHeal.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnHeal.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnHeal.FlatAppearance.BorderSize = 0;
            this.btnHeal.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnHeal.Font = new System.Drawing.Font("Cooper Black", 15F);
            this.btnHeal.Location = new System.Drawing.Point(504, 620);
            this.btnHeal.Name = "btnHeal";
            this.btnHeal.Size = new System.Drawing.Size(160, 40);
            this.btnHeal.TabIndex = 21;
            this.btnHeal.Text = "Heal (1)";
            this.btnHeal.UseVisualStyleBackColor = false;
            this.btnHeal.Click += new System.EventHandler(this.btnHeal_Click);
            // 
            // lblLeftMonster
            // 
            this.lblLeftMonster.Font = new System.Drawing.Font("Cooper Black", 9F);
            this.lblLeftMonster.Location = new System.Drawing.Point(493, 15);
            this.lblLeftMonster.Name = "lblLeftMonster";
            this.lblLeftMonster.Size = new System.Drawing.Size(180, 40);
            this.lblLeftMonster.TabIndex = 22;
            this.lblLeftMonster.Text = "Number of monsters left before the boss";
            this.lblLeftMonster.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblNumber
            // 
            this.lblNumber.Font = new System.Drawing.Font("Cooper Black", 22F);
            this.lblNumber.Location = new System.Drawing.Point(541, 54);
            this.lblNumber.Name = "lblNumber";
            this.lblNumber.Size = new System.Drawing.Size(80, 80);
            this.lblNumber.TabIndex = 9;
            this.lblNumber.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // FightForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.ClientSize = new System.Drawing.Size(1182, 853);
            this.Controls.Add(this.lblNumber);
            this.Controls.Add(this.lblLeftMonster);
            this.Controls.Add(this.btnHeal);
            this.Controls.Add(this.btnSkill);
            this.Controls.Add(this.btnAttack);
            this.Controls.Add(this.btnFight);
            this.Controls.Add(this.btnRun);
            this.Controls.Add(this.lblVersus);
            this.Controls.Add(this.picM3);
            this.Controls.Add(this.picM2);
            this.Controls.Add(this.picC4);
            this.Controls.Add(this.picM1);
            this.Controls.Add(this.picC3);
            this.Controls.Add(this.picM4);
            this.Controls.Add(this.picC2);
            this.Controls.Add(this.groupMonsterStatus);
            this.Controls.Add(this.picC1);
            this.Controls.Add(this.groupPlayerStatus);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "FightForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Fight!";
            this.Load += new System.EventHandler(this.FightForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picC4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC1)).EndInit();
            this.groupPlayerStatus.ResumeLayout(false);
            this.groupMonsterStatus.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.picM4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picM1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picM2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picM3)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox picC4;
        private System.Windows.Forms.PictureBox picC3;
        private System.Windows.Forms.PictureBox picC2;
        private System.Windows.Forms.PictureBox picC1;
        private System.Windows.Forms.GroupBox groupPlayerStatus;
        private System.Windows.Forms.Label lblLeftSPD;
        private System.Windows.Forms.Label lblLeftDEF;
        private System.Windows.Forms.Label lblLeftATK;
        private System.Windows.Forms.Label lblLeftHP;
        private System.Windows.Forms.Label lblPlayerSPD;
        private System.Windows.Forms.Label lblPlayerDEF;
        private System.Windows.Forms.Label lblPlayerATK;
        private System.Windows.Forms.Label lblPlayerHP;
        private System.Windows.Forms.GroupBox groupMonsterStatus;
        private System.Windows.Forms.Label lblRightSPD;
        private System.Windows.Forms.Label lblRightDEF;
        private System.Windows.Forms.Label lblRightATK;
        private System.Windows.Forms.Label lblRightHP;
        private System.Windows.Forms.Label lblMonsterSPD;
        private System.Windows.Forms.Label lblMonsterDEF;
        private System.Windows.Forms.Label lblMonsterATK;
        private System.Windows.Forms.Label lblMonsterHP;
        private System.Windows.Forms.PictureBox picM4;
        private System.Windows.Forms.PictureBox picM1;
        private System.Windows.Forms.PictureBox picM2;
        private System.Windows.Forms.PictureBox picM3;
        private System.Windows.Forms.Label lblVersus;
        private System.Windows.Forms.Button btnFight;
        private System.Windows.Forms.Button btnRun;
        private System.Windows.Forms.Button btnAttack;
        private System.Windows.Forms.Button btnSkill;
        private System.Windows.Forms.Button btnHeal;
        private System.Windows.Forms.Label lblLeftMonster;
        private System.Windows.Forms.Label lblNumber;
    }
}