using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LCL.MBK.QuickSortMeasure
{
    class Program
    {
        static int Main(string[] args)
        {
            int[] data = File.ReadAllLines(args[0]).Select(l => int.Parse(l)).ToArray();

            long before = DateTime.Now.Ticks;

            Algorithms.QuickSort.Sort(data);

            long after = DateTime.Now.Ticks;

            for (int i = 0; i < data.Length - 1; ++i)
            {
                if (data[i] > data[i + 1])
                {
                    System.Console.Error.Write("Incorrect sorting!");
                    return 1;
                }
            }

            System.Console.Out.Write("Time: " + (after - before) / 10000 + " ticks");
            return 0;
        }
    }
}
