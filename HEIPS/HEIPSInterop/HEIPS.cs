using System;
using System.Runtime.InteropServices;

namespace HEIPSInterop
{
    public class HEIPS
    {

        [DllImport(@"HEIPS.dll",EntryPoint = "HEIPSLoad", CharSet = CharSet.Ansi, SetLastError = true, CallingConvention=CallingConvention.Cdecl)]
        static extern bool HEIPSLoad([MarshalAs(UnmanagedType.LPStr)]string path);




        public bool Load(string file)
        {
            return HEIPSLoad(file);
        }



    }
}
