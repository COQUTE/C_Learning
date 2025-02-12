using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QW1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Add_Click(object sender, EventArgs e)
        {
            try {
                double result = double.Parse(textBox1.Text) + double.Parse(textBox2.Text);
                txtBoxResult.Text = "" + result;
            }
            catch(Exception e0)
            {
                MessageBox.Show(e0.Message);
            }
        }

        private void Sub_Click(object sender, EventArgs e)
        {
            try
            {
                double result = double.Parse(textBox1.Text) - double.Parse(textBox2.Text);
                txtBoxResult.Text = "" + result;
            }
            catch (Exception e0)
            {
                MessageBox.Show(e0.Message);
            }
        }

        private void Mul_Click(object sender, EventArgs e)
        {
            try
            {
                double result = double.Parse(textBox1.Text) * double.Parse(textBox2.Text);
                txtBoxResult.Text = "" + result;
            }
            catch (Exception e0)
            {
                MessageBox.Show(e0.Message);
            }
        }

        private void Div_Click(object sender, EventArgs e)
        {
            
            try
            {
                int check = int.Parse(textBox1.Text) / int.Parse(textBox2.Text);

                double result = double.Parse(textBox1.Text) / double.Parse(textBox2.Text);
                txtBoxResult.Text = "" + result;
            }
            catch (DivideByZeroException e1)
            {
                MessageBox.Show(e1.Message);
            }
            catch (Exception e0)
            {
                MessageBox.Show(e0.Message);
            }
        }
    }
}
