using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LCL.MBK.Algorithms
{
    public static class QuickSort
    {
        public static void Sort(int[] data)
        {
            Sort(data, 0, data.Length - 1);
        }

        private static void Sort(int[] data, int start, int end)
        {
            if (start >= end)
                return;

            int pivot = start;

            for (int i = start + 1; i <= end; ++i)
            {
                if (data[i] < data[pivot])
                {
                    if (pivot + 1 != i)
                        Swap(data, pivot, pivot + 1);
                    Swap(data, pivot, i);
                    pivot += 1;
                }
            }

            if (pivot > start)
                Sort(data, start, pivot - 1);
            if (pivot < end)
                Sort(data, pivot + 1, end);
        }

        private static void Swap(int[] data, int i, int j)
        {
            int val = data[i];
            data[i] = data[j];
            data[j] = val;
        }
    }
}
