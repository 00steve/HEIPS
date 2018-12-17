using System.Runtime.InteropServices;

namespace HEIPSInterop
{
    public class HEIPS
    {


        [DllImport("HEIPS.dll", EntryPoint = "HEIPSImageFileName")]
        [return: MarshalAs(UnmanagedType.LPStr)]
        static extern string HEIPSImageFileName();
        public string ImageFileName()
        {
            return HEIPSImageFileName();
        }

        [DllImport("HEIPS.dll", EntryPoint = "HEIPSImageHeight")]
        static extern int HEIPSImageHeight();
        public int ImageHeight()
        {
            return HEIPSImageHeight();
        }




        [DllImport("HEIPS.dll", EntryPoint = "HEIPSImageLoaded")]
        static extern bool HEIPSImageLoaded();
        public bool ImageLoaded()
        {
            return HEIPSImageLoaded();
        }



        [DllImport("HEIPS.dll", EntryPoint = "HEIPSImageWidth")]
        static extern int HEIPSImageWidth();
        public int ImageWidth()
        {
            return HEIPSImageWidth();
        }



        [DllImport("HEIPS.dll", EntryPoint = "HEIPSLoad")]
        static extern bool HEIPSLoad(string path);
        public bool Load(string path)
        {
            return HEIPSLoad(path);
        }

    

     

    }
}
