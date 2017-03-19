using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataGenerator
{
    class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random((int)DateTime.Now.Millisecond);

            if (args.Length < 1)
                return;

            switch (args[0].ToLower())
            {
                case "r":
                    GenerateResampled(random, int.Parse(args[1]));
                    break;
                case "s":
                    GenerateSimple(random);
                    break;
                case "w":
                    GenerateTimeWarped(random);
                    break;
				case "z":
					GenerateZeros();
					break;
                default:
                    Console.Out.WriteLine("Unknown argument");
                    break;
            }
        }

		///////////////////////////////////////////////////////////////////////////////////////////
		private static void GenerateZeros()
		{
			OutputFile(new List<double> { 0, 0, 0 }, "zeros.dat");
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		private static void GenerateSimple(Random random)
        {
            OutputFile(GenerateBaseData(random), "simple.dat");
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static void GenerateTimeWarped(Random random)
        {
            List<int> baseData = GenerateBaseData(random);

            List<int> version1 = new List<int>();
            List<int> version2 = new List<int>();

            int lastValue = 0;
            foreach (int value in baseData)
            {
                if (random.Next() % 2 == 0)
                    version1.Add(lastValue + (value - lastValue) / 2);
                version1.Add(value);

                if (random.Next() % 3 == 0)
                {
                    version2.Add(lastValue + 1 * (value - lastValue) / 3);
                    version2.Add(lastValue + 2 * (value - lastValue) / 3);
                }
                version2.Add(value);

                lastValue = value;
            }

            OutputFile(version1, "warped1.dat");
            OutputFile(version2, "warped2.dat");
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static void GenerateResampled(Random random, int factor)
        {
            List<int> baseData = GenerateBaseData(random);

            List<double> resampled = new List<double>();

            int lastValue = 0;
            foreach (int value in baseData)
            {
                double diff = value - lastValue;
                resampled.Add(value - diff / (double)factor);
                lastValue = value;
            }

            OutputFile(baseData, "resampledSource.dat");
            OutputFile(resampled, "resampledResult.dat");
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static void OutputFile<T>(List<T> data, string fileName)
        {
            if (File.Exists(fileName))
                File.Delete(fileName);

            File.WriteAllLines(fileName, data.Select(d => d.ToString()).ToArray());
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static List<int> GenerateBaseData(Random random)
        {
            List<int> data = new List<int>();

            int value = 0;
            for (int i = 0; i < 2048; ++i)
            {
                value += random.Next(0, 16);
                data.Add(value);
            }

            return data;
        }
    }
}
