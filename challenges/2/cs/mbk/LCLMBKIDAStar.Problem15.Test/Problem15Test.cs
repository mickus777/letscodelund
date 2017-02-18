using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LCLMBKIDAStar.Problem15.Test
{
    [TestClass]
    public class Problem15Test
    {
        [TestMethod]
        public void Problem15_HasSolution()
        {
            State start = new State(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14 });

            Assert.IsTrue(start.HasSolution());
        }

        [TestMethod]
        public void Problem15_HasSolution_Data3()
        {
            State start = new State(new List<int> { 5, 2, 15, 3, 12, 4, 0, 6, 1, 9, 11, 7, 8, 13, 10, 14 });

            Assert.IsTrue(start.HasSolution());
        }

        [TestMethod]
        public void Problem15_HasSolution_Data4()
        {
            State start = new State(new List<int> { 14, 13, 7, 11, 9, 10, 8, 12, 1, 5, 4, 0, 2, 6, 3, 15 });

            Assert.IsFalse(start.HasSolution());
        }

        [TestMethod]
        public void Problem15_Search_Data3()
        {
            State start = new State(new List<int> { 5, 2, 15, 3, 12, 4, 0, 6, 1, 9, 11, 7, 8, 13, 10, 14 });

            State result = (State)IDAStar.Search(start);

            Assert.AreEqual(28, result.PreviousStates.Count);
        }

        [TestMethod]
        public void Problem15_Search_Data5()
        {
            State start = new State(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 15, 9, 10, 11, 8, 12, 13, 14 });

            State result = (State)IDAStar.Search(start);

            Assert.AreEqual(4, result.PreviousStates.Count);
        }


        [TestMethod]
        public void Problem15_Search()
        {
            State start = new State(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14 });

            State result = (State)IDAStar.Search(start);

            Assert.AreEqual(1, result.PreviousStates.Count);
        }

        [TestMethod]
        public void Problem15_PossibleMoves()
        {
            State start = new State(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14 });

            List<State> moves = start.Successors().Cast<State>().ToList();

            Assert.AreEqual(3, moves.Count);
            CollectionAssert.AreEqual(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, moves[0].Board);
            CollectionAssert.AreEqual(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 13, 14 }, moves[1].Board);
            CollectionAssert.AreEqual(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 11, 12, 13, 10, 14 }, moves[2].Board);
        }

        [TestMethod]
        public void Problem15_PossibleMoves_Data5()
        {
            State start = new State(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 15, 9, 10, 11, 8, 12, 13, 14 });

            List<State> moves = start.Successors().Cast<State>().ToList();

            Assert.AreEqual(3, moves.Count);
            CollectionAssert.AreEqual(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 15, 12, 13, 14 }, moves[0].Board);
            CollectionAssert.AreEqual(new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 9, 15, 10, 11, 8, 12, 13, 14 }, moves[1].Board);
            CollectionAssert.AreEqual(new List<int> { 0, 1, 2, 3, 15, 5, 6, 7, 4, 9, 10, 11, 8, 12, 13, 14 }, moves[2].Board);
         }
    }
}
