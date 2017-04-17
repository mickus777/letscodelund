using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace TidyNumbersCS
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            //Application.EnableVisualStyles();
            //Application.SetCompatibleTextRenderingDefault(false);
            //Application.Run(new Form1());

            string fileName = "B-large.in";

            string[] lines = File.ReadAllLines(@"C:\test\proj2\" + fileName);

            long[] testCases = new long[Int32.Parse(lines[0])];
            
            Controller ctrl = new Controller();
            for (int i = 0; i < testCases.Length; i++)
                testCases[i] = ctrl.Control(Int64.Parse(lines[i + 1]));

            using (StreamWriter outputFile = new StreamWriter(@"C:\test\OUTPUT" + fileName))
            {
                for (int i = 0; i < testCases.Length; i++) {
                    int j = i + 1;
                outputFile.WriteLine("Case #" + j + ": " + testCases[i].ToString());
            }
            }

        }

    }
}
