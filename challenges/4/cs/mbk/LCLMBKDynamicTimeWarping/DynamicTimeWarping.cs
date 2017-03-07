using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LCL.MBK.Algorithms
{
    public class DynamicTimeWarping
    {
        ///////////////////////////////////////////////////////////////////////////////////////////
        public static double Execute<T>(T[] a1, T[] a2, Func<T, T, double> compare)
        {
            double[,] dtw = new double[a1.Length + 1, a2.Length + 1];
            for (int i = 0; i <= a1.Length; ++i)
                dtw[i, 0] = double.PositiveInfinity;
            for (int i = 0; i <= a2.Length; ++i)
                dtw[0, i] = double.PositiveInfinity;
            dtw[0, 0] = 0;

            for (int i1 = 0; i1 < a1.Length; ++i1)
                for (int i2 = 0; i2 < a2.Length; ++i2)
                    dtw[i1 + 1, i2 + 1] = compare(a1[i1], a2[i2]) + Min(dtw[i1, i2 + 1], dtw[i1 + 1, i2], dtw[i1, i2]);

            return dtw[a1.Length, a2.Length];
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static double Min(double d1, double d2, double d3)
        {
            return Math.Min(d1, Math.Min(d2, d3));
        }
    }
}
