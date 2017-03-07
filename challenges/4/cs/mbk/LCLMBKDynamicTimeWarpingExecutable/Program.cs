using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LCL.MBK.Algorithms.DynamicTimeWarpingExecutable
{
    class Program
    {
        ///////////////////////////////////////////////////////////////////////////////////////////
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.Out.WriteLine("Usage: [-d] <input_file_1> <input_file_2>");
                Console.Out.WriteLine("       -d Indicates that the input files each contain a list of double values, separated by line breaks.");
                return;
            }

            double difference = 0;

            if (args[0].ToLower() == "-d")
            {
                difference = DynamicTimeWarping.Execute(ParseTextFile(args[1]), ParseTextFile(args[2]), (d1, d2) => Math.Abs(d1 - d2));
            }
            else
            {
                Console.Error.WriteLine("Unable to parse files of type: " + args[0]);
                return;
            }

            Console.Out.WriteLine("Difference " + difference.ToString());
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static double[] ParseTextFile(string path)
        {
            return File.ReadAllLines(path).Select(l => double.Parse(l)).ToArray();
        }
    }
}
