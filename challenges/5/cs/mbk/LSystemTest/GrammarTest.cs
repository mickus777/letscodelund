using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LSystemTest
{
    [TestClass]
    public class GrammarTest
    {
        ///////////////////////////////////////////////////////////////////////////////////////////
        [TestMethod]
        public void LSystem_Example1()
        {
            LSystem.Grammar grammar = new LSystem.Grammar("A", new Dictionary<string, string> { { "A", "AB" }, { "B", "A" } });
            Assert.AreEqual("A", grammar.Value);

            grammar.Iterate();
            Assert.AreEqual("AB", grammar.Value);

            grammar.Iterate();
            Assert.AreEqual("ABA", grammar.Value);

            grammar.Iterate();
            Assert.AreEqual("ABAAB", grammar.Value);

            grammar.Iterate();
            Assert.AreEqual("ABAABABA", grammar.Value);

            grammar.Iterate();
            Assert.AreEqual("ABAABABAABAAB", grammar.Value);

            grammar.Iterate();
            Assert.AreEqual("ABAABABAABAABABAABABA", grammar.Value);

            grammar.Iterate();
            Assert.AreEqual("ABAABABAABAABABAABABAABAABABAABAAB", grammar.Value);
        }
    }
}
