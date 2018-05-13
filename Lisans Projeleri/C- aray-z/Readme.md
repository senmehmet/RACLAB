using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;	
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.IO.Ports;

namespace TankOtomasyonu
{
    public partial class Form1 : Form
    {
        int gidenVeri;
        Thread t;
        IPAddress ipadresimiz;
        TcpListener dinle;
        Socket soket;
        NetworkStream ag;
        StreamReader oku;
        StreamWriter yaz;
        public delegate void ricdegis(string text);
        public void okumayabasla()
        {
            soket = dinle.AcceptSocket();
            ag = new NetworkStream(soket);
            oku = new StreamReader(ag);
            while(true)
            {
                try
                {
                    string yazi = oku.ReadLine();
                    ekranabas(yazi);
                }
                catch
                {
                    return;
                }
            }
        }
        public void ekranabas(string s)
        {
            if(this.InvokeRequired)
            {
                ricdegis degis = new ricdegis(ekranabas);
                this.Invoke(degis, s);

            }
            else
            {
                s = "" + s;
                textBox1.AppendText(s + "\n");
            }
        }
        private void dinlemeye_basla()
        {
            ipadresimiz = IPAddress.Parse("172.20.10.2");
            dinle = new TcpListener(ipadresimiz, Convert.ToInt16(textBox1.Text));
            dinle.Start();
            t = new Thread(new ThreadStart(okumayabasla));
            t.Start();
            textBox1.AppendText(DateTime.Now.ToString() + "Baglanti Yapildi...\n");
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
            timer1.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           
            dinlemeye_basla();
        }

        private void button6_Click(object sender, EventArgs e)
        {
           
            yaz = new StreamWriter(ag);
            yaz.WriteLine("w");
            yaz.Flush();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            yaz = new StreamWriter(ag);
            yaz.WriteLine("a");
            yaz.Flush();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            yaz = new StreamWriter(ag);
            yaz.WriteLine("d");
            yaz.Flush();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            yaz = new StreamWriter(ag);
            yaz.WriteLine("d");
            yaz.Flush();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            yaz = new StreamWriter(ag);
            yaz.WriteLine("a");
            yaz.Flush();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            yaz = new StreamWriter(ag);
            yaz.WriteLine("f");
            yaz.Flush();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            webBrowser1.Navigate("http://172.20.10.7:8080");
        }


        private void timer1_Tick(object sender, EventArgs e)
        {
            label4.Text = DateTime.Now.ToLongTimeString();
            label5.Text = DateTime.Now.ToShortDateString();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            webBrowser2.Navigate("https://www.google.com/android/find?hl=tr&u=0&rapt=AEjHL4PB85x6LSRhkdzm_y85knsIIyaDcfG378v2a_UZS2ZruJ1iSY5_bV4sL7bAU6gVsj9A0M_AADZeQ1VJ0UECqXfh9hUF1g");
        }
    }
