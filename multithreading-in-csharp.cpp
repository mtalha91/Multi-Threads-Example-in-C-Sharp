using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TPL5
{
    public partial class Form1 : Form
    {
        public Thread threadid1;
        public Thread threadid2;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Mohammad Talha - L14-5011
            // Manahil Hassan - L15-5006
        }

        private void start_Click(object sender, EventArgs e)
        {
            message.Text = "Threads Starts";

            // Enable buttons
            sync.Enabled = true;
            quite.Enabled = true;

            // Starts threads
            threadid1 = new Thread(new ThreadStart(Thread1));
            threadid2 = new Thread(new ThreadStart(Thread2));
            threadid1.Start();
            threadid2.Start();
        }

        private void sync_Click(object sender, EventArgs e)
        {
            start.Enabled = false;
            unsync.Enabled = true;

            // Stop threads
            threadid1.Abort();
            threadid2.Abort();

            threadid1 = new Thread(new ThreadStart(Thread1));
            threadid2 = new Thread(new ThreadStart(Thread2));
            threadid1.Start();
            Thread.Sleep(750); // deplay to the theads 500 + 1000 / 2 = 750 ..  this will sychronized the threads , and execute the threads one by one
            threadid2.Start();

            message.Text = "Threads Synchronized";
        }

        private void unsync_Click(object sender, EventArgs e)
        {
            // Stop threads
            threadid1.Abort();
            threadid2.Abort();

            // Starts threads
            threadid1 = new Thread(new ThreadStart(Thread1));
            threadid2 = new Thread(new ThreadStart(Thread2));
            threadid1.Start();
            threadid2.Start();

            message.Text = "Threads Unsynchronized";
            Console.WriteLine("Unsync Threads");
        }

        private void quite_Click(object sender, EventArgs e)
        {
            // Stop threads
            threadid1.Abort();
            threadid2.Abort();
            // Stop threads garphics
            this.Invalidate();

            start.Enabled = true;
            sync.Enabled = false;
            unsync.Enabled = false;

            message.Text = "Threads stopped";
            Console.WriteLine("Stop Threads");
        }
        public void Thread1()
        {

            for (int i = 0; i < 10; i++)
            {
                try {
                    Console.WriteLine("Thread {0} started" + i, Thread.CurrentThread.Name);

                    System.Drawing.Graphics graphicsObj;
                    graphicsObj = this.CreateGraphics();

                    Pen myPent1 = new Pen(System.Drawing.Color.Red, 2);
                    Rectangle myRectangle = new Rectangle(40, 80, 150, 150);
                    graphicsObj.DrawRectangle(myPent1, myRectangle);

                    Thread.Sleep(500);
                    Console.WriteLine("Thread {0} completed" + i, Thread.CurrentThread.Name);

                    this.Invalidate();
                    Thread.Sleep(1000);
                } catch (Exception e) {
                    Console.WriteLine(e.ToString());
                }
                
            }
        }
        public void Thread2()
        {
            for (int i = 0; i < 10; i++)
            {
                try {
                    Console.WriteLine("Thread {0} started" + i, Thread.CurrentThread.Name);
                    // MessageBox.Show("Start Threads 2");
                    System.Drawing.Graphics graphicsObj;
                    graphicsObj = this.CreateGraphics();

                    Pen myPent2 = new Pen(System.Drawing.Color.Green, 2);
                    Rectangle myCircle = new Rectangle(310, 80, 150, 150);
                    graphicsObj.DrawEllipse(myPent2, myCircle);

                    Thread.Sleep(500);
                    Console.WriteLine("Thread {0} completed" + i, Thread.CurrentThread.Name);

                    this.Invalidate();
                    Thread.Sleep(1000);
                } catch(Exception e) {
                    Console.WriteLine(e.ToString());
                }
                
            }
        }
    }
}