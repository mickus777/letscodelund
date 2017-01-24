using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LCL.MBK.QuickSortTest
{
    [TestClass]
    public class TestQuickSort
    {
        [TestMethod]
        public void QuickSort_Sort()
        {
            int[] data = new int[] { 3, 5, 7, 2, 1, 6, 4 };

            LCL.MBK.Algorithms.QuickSort.Sort(data);

            int[] expected = new[] { 1, 2, 3, 4, 5, 6, 7 };

            CollectionAssert.AreEqual(expected, data);
        }
    }
}
