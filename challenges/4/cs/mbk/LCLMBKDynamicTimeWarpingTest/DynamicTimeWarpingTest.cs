using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LCL.MBK.Algorithms.DynamicTimeWarpingTest
{
    [TestClass]
    public class DynamicTimeWarpingTest
    {
        private static double IntCompare(int i1, int i2)
        {
            return Math.Abs(i1 - i2);
        }

        [TestMethod]
        public void DynamicTimeWarping_Execute()
        {
            int[] a1 = new int[] { 1, 2, 3, 4, 5 };
            int[] a2 = new int[] { 1, 2, 3, 4, 5 };

            Assert.AreEqual(0, LCL.MBK.Algorithms.DynamicTimeWarping.Execute(a1, a2, IntCompare));
        }

        [TestMethod]
        public void DynamicTimeWarping_Execute_AlmostSame()
        {
            int[] a1 = new int[] { 1, 2, 3, 4, 5 };
            int[] a2 = new int[] { 1, 2, 5, 4, 5 };

            Assert.AreEqual(2, LCL.MBK.Algorithms.DynamicTimeWarping.Execute(a1, a2, IntCompare));
        }

        [TestMethod]
        public void DynamicTimeWarping_Execute_NotSame()
        {
            int[] a1 = new int[] { 1, 2, 3, 4, 5 };
            int[] a2 = new int[] { 10, 9, 8, 7, 6 };

            Assert.AreEqual(25, LCL.MBK.Algorithms.DynamicTimeWarping.Execute(a1, a2, IntCompare));
        }
    }
}
