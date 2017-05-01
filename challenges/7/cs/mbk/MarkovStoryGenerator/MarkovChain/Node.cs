using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MarkovChain
{
    public class Node<T>
    {
        private Dictionary<T, Node<T>> Children = new Dictionary<T, Node<T>>();

        private int Count = 0;
        private double Fraction = 0;

        ///////////////////////////////////////////////////////////////////////////////////////////
        public void Add(IEnumerable<T> path, T value)
        {
            if (path.Count() == 0)
            {
                if (!Children.ContainsKey(value))
                    Children[value] = new Node<T>();
                Children[value].Count += 1;
            }
            else
            {
                T next = path.First();
                if (!Children.ContainsKey(next))
                    Children[next] = new Node<T>();
                Children[next].Count += 1;
                Children[next].Add(path.Skip(1), value);
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public void Normalize()
        {
            double total = 0;

            foreach (KeyValuePair<T, Node<T>> child in Children)
            {
                child.Value.Normalize();
                total += child.Value.Count;
            }

            foreach (KeyValuePair<T, Node<T>> child in Children)
                child.Value.Fraction = child.Value.Count / total;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public T GenerateNext(Random randomizer, IEnumerable<T> path)
        {
            if (path.Count() > 0)
                return Children[path.First()].GenerateNext(randomizer, path.Skip(1));

            double value = randomizer.NextDouble();

            foreach (KeyValuePair<T, Node<T>> child in Children)
            {
                if (value > child.Value.Fraction)
                    value -= child.Value.Fraction;
                else
                    return child.Key;
            }

            throw new Exception("Should never get here.");
        }
    }
}
