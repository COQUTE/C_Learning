
namespace Project
{
    partial class SelectionForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SelectionForm));
            this.picC1 = new System.Windows.Forms.PictureBox();
            this.picC2 = new System.Windows.Forms.PictureBox();
            this.lblTitle = new System.Windows.Forms.Label();
            this.picC3 = new System.Windows.Forms.PictureBox();
            this.picC4 = new System.Windows.Forms.PictureBox();
            this.btnC1 = new System.Windows.Forms.RadioButton();
            this.btnC4 = new System.Windows.Forms.RadioButton();
            this.btnC2 = new System.Windows.Forms.RadioButton();
            this.btnC3 = new System.Windows.Forms.RadioButton();
            this.btnSelect = new System.Windows.Forms.Button();
            this.btnBack = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.picC1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC4)).BeginInit();
            this.SuspendLayout();
            // 
            // picC1
            // 
            this.picC1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.picC1.Image = ((System.Drawing.Image)(resources.GetObject("picC1.Image")));
            this.picC1.Location = new System.Drawing.Point(10, 80);
            this.picC1.Name = "picC1";
            this.picC1.Size = new System.Drawing.Size(380, 370);
            this.picC1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picC1.TabIndex = 0;
            this.picC1.TabStop = false;
            this.picC1.Click += new System.EventHandler(this.picC1_Click);
            // 
            // picC2
            // 
            this.picC2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.picC2.Image = ((System.Drawing.Image)(resources.GetObject("picC2.Image")));
            this.picC2.Location = new System.Drawing.Point(430, 80);
            this.picC2.Name = "picC2";
            this.picC2.Size = new System.Drawing.Size(260, 370);
            this.picC2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picC2.TabIndex = 1;
            this.picC2.TabStop = false;
            this.picC2.Click += new System.EventHandler(this.picC2_Click);
            // 
            // lblTitle
            // 
            this.lblTitle.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblTitle.Font = new System.Drawing.Font("Cooper Black", 18F);
            this.lblTitle.Location = new System.Drawing.Point(0, 0);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(1282, 49);
            this.lblTitle.TabIndex = 2;
            this.lblTitle.Text = "Choose your character!";
            this.lblTitle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // picC3
            // 
            this.picC3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.picC3.Image = ((System.Drawing.Image)(resources.GetObject("picC3.Image")));
            this.picC3.Location = new System.Drawing.Point(730, 80);
            this.picC3.Name = "picC3";
            this.picC3.Size = new System.Drawing.Size(260, 370);
            this.picC3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picC3.TabIndex = 3;
            this.picC3.TabStop = false;
            this.picC3.Click += new System.EventHandler(this.picC3_Click);
            // 
            // picC4
            // 
            this.picC4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.picC4.Image = ((System.Drawing.Image)(resources.GetObject("picC4.Image")));
            this.picC4.Location = new System.Drawing.Point(1030, 80);
            this.picC4.Name = "picC4";
            this.picC4.Size = new System.Drawing.Size(240, 370);
            this.picC4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picC4.TabIndex = 4;
            this.picC4.TabStop = false;
            this.picC4.Click += new System.EventHandler(this.picC4_Click);
            // 
            // btnC1
            // 
            this.btnC1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnC1.Font = new System.Drawing.Font("Cooper Black", 9F);
            this.btnC1.Location = new System.Drawing.Point(150, 480);
            this.btnC1.Name = "btnC1";
            this.btnC1.Size = new System.Drawing.Size(100, 20);
            this.btnC1.TabIndex = 5;
            this.btnC1.TabStop = true;
            this.btnC1.Text = "Warrior";
            this.btnC1.UseVisualStyleBackColor = true;
            // 
            // btnC4
            // 
            this.btnC4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnC4.Font = new System.Drawing.Font("Cooper Black", 9F);
            this.btnC4.Location = new System.Drawing.Point(1100, 480);
            this.btnC4.Name = "btnC4";
            this.btnC4.Size = new System.Drawing.Size(100, 20);
            this.btnC4.TabIndex = 6;
            this.btnC4.TabStop = true;
            this.btnC4.Text = "Archor";
            this.btnC4.UseVisualStyleBackColor = true;
            // 
            // btnC2
            // 
            this.btnC2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnC2.Font = new System.Drawing.Font("Cooper Black", 9F);
            this.btnC2.Location = new System.Drawing.Point(510, 480);
            this.btnC2.Name = "btnC2";
            this.btnC2.Size = new System.Drawing.Size(100, 20);
            this.btnC2.TabIndex = 7;
            this.btnC2.TabStop = true;
            this.btnC2.Text = "Wizard";
            this.btnC2.UseVisualStyleBackColor = true;
            // 
            // btnC3
            // 
            this.btnC3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnC3.Font = new System.Drawing.Font("Cooper Black", 9F);
            this.btnC3.Location = new System.Drawing.Point(810, 475);
            this.btnC3.Name = "btnC3";
            this.btnC3.Size = new System.Drawing.Size(100, 30);
            this.btnC3.TabIndex = 6;
            this.btnC3.TabStop = true;
            this.btnC3.Text = "knight";
            this.btnC3.UseVisualStyleBackColor = true;
            // 
            // btnSelect
            // 
            this.btnSelect.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnSelect.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnSelect.FlatAppearance.BorderSize = 0;
            this.btnSelect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSelect.Font = new System.Drawing.Font("Cooper Black", 12F);
            this.btnSelect.Location = new System.Drawing.Point(870, 540);
            this.btnSelect.Name = "btnSelect";
            this.btnSelect.Size = new System.Drawing.Size(200, 50);
            this.btnSelect.TabIndex = 8;
            this.btnSelect.Text = "Select !";
            this.btnSelect.UseVisualStyleBackColor = false;
            this.btnSelect.Click += new System.EventHandler(this.btnSelect_Click);
            // 
            // btnBack
            // 
            this.btnBack.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.btnBack.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnBack.FlatAppearance.BorderSize = 0;
            this.btnBack.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnBack.Font = new System.Drawing.Font("Cooper Black", 12F);
            this.btnBack.Location = new System.Drawing.Point(230, 540);
            this.btnBack.Name = "btnBack";
            this.btnBack.Size = new System.Drawing.Size(200, 50);
            this.btnBack.TabIndex = 10;
            this.btnBack.Text = "Back";
            this.btnBack.UseVisualStyleBackColor = false;
            this.btnBack.Click += new System.EventHandler(this.btnBack_Click);
            // 
            // SelectionForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.ClientSize = new System.Drawing.Size(1282, 603);
            this.Controls.Add(this.btnBack);
            this.Controls.Add(this.btnSelect);
            this.Controls.Add(this.btnC2);
            this.Controls.Add(this.btnC3);
            this.Controls.Add(this.btnC4);
            this.Controls.Add(this.btnC1);
            this.Controls.Add(this.picC4);
            this.Controls.Add(this.picC3);
            this.Controls.Add(this.lblTitle);
            this.Controls.Add(this.picC2);
            this.Controls.Add(this.picC1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "SelectionForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Characters";
            this.Load += new System.EventHandler(this.selectionForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picC1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picC4)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox picC1;
        private System.Windows.Forms.PictureBox picC2;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.PictureBox picC3;
        private System.Windows.Forms.PictureBox picC4;
        private System.Windows.Forms.RadioButton btnC1;
        private System.Windows.Forms.RadioButton btnC4;
        private System.Windows.Forms.RadioButton btnC2;
        private System.Windows.Forms.RadioButton btnC3;
        private System.Windows.Forms.Button btnSelect;
        private System.Windows.Forms.Button btnBack;
    }
}