using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MarkovChain
{
    public class Chain<T>
    {
        private Node<T> Root = new Node<T>();
        private int WindowSize;

        public List<T> TopNodes { get; private set; }
        private T End;

        ///////////////////////////////////////////////////////////////////////////////////////////
        public Chain(int windowSize, T end)
        {
            WindowSize = windowSize;
            End = end;

            TopNodes = new List<T>();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public void Read(IEnumerable<T> input)
        {
            List<T> path = new List<T>();
            Root.Add(path, input.First());
            path.Add(input.First());
            TopNodes.Add(input.First());

            foreach (T token in input.Skip(1))
            {
                if (path.Count() > WindowSize - 1)
                    path.RemoveAt(0);
                Root.Add(path, token);
                path.Add(token);
            }

            path.Take(1);
            Root.Add(path, End);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public IEnumerable<T> Generate()
        {
            Root.Normalize();

            List<T> output = new List<T>();

            Random random = new Random((int)DateTime.Now.Ticks);

            T node = TopNodes[random.Next(0, TopNodes.Count - 1)];
            output.Add(node);

            List<T> path = new List<T>();
            path.Add(node);
            while (node.ToString() != End.ToString())
            {
                node = Root.GenerateNext(random, path);
                output.Add(node);

                path.Add(node);
                if (path.Count() > WindowSize - 1)
                    path.RemoveAt(0);
            }

            return output;
        }
    }
}
