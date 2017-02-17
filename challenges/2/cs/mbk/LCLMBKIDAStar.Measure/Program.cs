using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LCLMBKIDAStar.Measure
{
    class Program
    {
        private static Problem15.State ParseFile(string path)
        {
            string[] problemTextLines = File.ReadAllLines(path);

            List<int> values = new List<int>();

            for (int i = 0; i < 4; ++i)
            {
                string[] items = problemTextLines[i].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                for (int j = 0; j < 4; ++j)
                {
                    int item = 15;
                    int value;
                    if (int.TryParse(items[j], out value))
                        item = value - 1;
                    values.Add(item);
                }
            }

            return new Problem15.State(values);
        }

        static void Main(string[] args)
        {
            Problem15.State start = ParseFile(args[0]);

            Problem15.State end = (Problem15.State)IDAStar.Search(start);

            foreach (Problem15.State node in end.PreviousStates)
                System.Console.Out.WriteLine(node.ToString());

            System.Console.Out.WriteLine(end.PreviousStates.Count);
        }
    }
}
