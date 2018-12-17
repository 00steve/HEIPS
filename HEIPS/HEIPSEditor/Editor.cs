
using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Editor : Form
    {


        //[DllImport(@"HEIPS.dll", EntryPoint = "HEIPSLoad", CharSet = CharSet.Ansi, SetLastError = true, CallingConvention = CallingConvention.Cdecl)]
        [DllImport("HEIPS.dll", SetLastError = true)]
        static extern bool HEIPSLoad(string path);


        //[DllImport(@"HEIPS.dll", EntryPoint = "HEIPSLoad", CharSet = CharSet.Ansi, SetLastError = true, CallingConvention = CallingConvention.Cdecl)]
        [DllImport(@"HEIPS.dll",EntryPoint = "HEIPSs")]
        static extern int HEIPs(string path);



        public Editor()
        {
            InitializeComponent();
        }

        private void loadImageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string n = "egf";
            bool t = HEIPSLoad(n);
            int i = HEIPs(n);
            MessageBox.Show(n + ":" + (t? "yes":"no"));
            MessageBox.Show(i.ToString());


            n = "hjiofwejoifewoiwf";
            t = HEIPSLoad(n);
            i = HEIPs(n);
            MessageBox.Show(n + ":" + (t ? "yes" : "no"));


            MessageBox.Show(i.ToString());


            //HEIPS h = new HEIPS();
            // bool things = h.Load("things");
        }
    }
}
