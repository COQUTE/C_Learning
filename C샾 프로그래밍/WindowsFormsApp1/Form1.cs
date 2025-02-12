using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Child form = new Child();
            form.Show();
        }

        int imageNum = 0;

        private void timer1_Tick(object sender, EventArgs e)
        {
            pictureBox1.Image = imageList1.Images[imageNum];
            // imageList1의 이미지 총 개수로 imageNum + 1을 나눠줌
            imageNum = (imageNum + 1) % (imageList1.Images.Count);
        }

        /*
        새로운 폼 생성

        Child form = new Child();
        form.Show();
         */

        /*
        이미지 로드

        OpenFileDialog obj = new OpenFileDialog();
        if(obj.ShowDialog() == System.Windows.Forms.DialogResult.OK)
        {
            pictureBox1.ImageLocation = obj.FileName;
        }
         */
    }
}
