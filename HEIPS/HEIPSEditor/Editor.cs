
using HEIPSInterop;
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Editor : Form
    {



        public Editor()
        {
            InitializeComponent();
        }

        private void loadImageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            HEIPS h = new HEIPS();

            string n = "mr2.jpg";
            bool loaded = h.Load(n);
            bool imageLoaded = h.ImageLoaded();
            int imageHeight = h.ImageHeight();
            int imageWidth = h.ImageWidth();

            Debug.WriteLine("---GOOD LOAD-----");
            Debug.WriteLine("load image " + n);
            Debug.WriteLine("load image successful : " + imageLoaded.ToString());
            Debug.WriteLine(" - size : " + imageHeight.ToString() + " x " + imageWidth.ToString());

            n = "mr.jobs";
            loaded = h.Load(n);
            imageLoaded = h.ImageLoaded();
            imageHeight = h.ImageHeight();
            imageWidth = h.ImageWidth();

            Debug.WriteLine("---FAILURE LOAD-----");
            Debug.WriteLine("load image " + n);
            Debug.WriteLine("load image successful : " + imageLoaded.ToString());
            Debug.WriteLine(" - size : " + imageHeight.ToString() + " x " + imageWidth.ToString());



        }
    }
}
