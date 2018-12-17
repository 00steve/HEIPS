using System.Runtime.InteropServices;

namespace HEIPSInterop
{
    public class HEIPS
    {


        [DllImport(@"HEIPS.dll", EntryPoint = "HEIPSImageFileName")]
        [return: MarshalAs(UnmanagedType.LPStr)]
        static extern string HEIPSImageFileName();
        public string ImageFileName()
        {
            return HEIPSImageFileName();
        }



        [DllImport(@"HEIPS.dll", EntryPoint = "HEIPSLoad")]
        static extern bool HEIPSLoad(string path);
        public bool Load(string path)
        {
            return HEIPSLoad(path);
        }

    

        [DllImport(@"HEIPS.dll", EntryPoint = "HEIPSStringLength")]
        static extern int HEIPSStringLength(string path);
        public int StringLength(string path)
        {
            return HEIPSStringLength(path);
        }

    }
}
