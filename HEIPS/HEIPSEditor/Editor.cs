﻿
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
            string n = "mr2.jg";


            HEIPS h = new HEIPS();
            bool loaded = h.Load(n);
            
            Debug.WriteLine("load image " + n);

            //string loadedFile = h.ImageFileName();
            //Debug.WriteLine("loaded image : " + loadedFile);
            



        }
    }
}
