using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MarkovChain
{
    public class TextParser : IEnumerable<string>
    {
        private IEnumerable<string> Lines;

        ///////////////////////////////////////////////////////////////////////////////////////////
        public TextParser(IEnumerable<string> lines)
        {
            Lines = lines;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public static string EnumerateChunk(ref int position, string text)
        {
            string word = "";

            while (position < text.Length)
            {
                char ch = text[position];
                switch (ch)
                {
                    case ' ':
                    case '\r':
                    case '\n':
                        return word;
                    default:
                        ++position;
                        word += ch;
                        break;
                }
            }

            return word;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public IEnumerator<string> GetEnumerator()
        {
            yield return "[[START]]";

            foreach (string line in Lines.Select(l => l.Trim().ToLower()))
            {
                if (line.Length == 0)
                {
                    yield return "[[PARAGRAPHBREAK]]";
                }
                else
                {
                    int position = 0;

                    while (position < line.Length)
                    {
                        string chunk = EnumerateChunk(ref position, line);

                        List<string> leftToYield = new List<string>();

                        if (chunk.EndsWith("’"))
                        {
                            chunk = chunk.Substring(0, chunk.Length - 1);
                        }
                        if (chunk.EndsWith(".") || chunk.EndsWith(";") || chunk.EndsWith(":") || chunk.EndsWith("!") || chunk.EndsWith("?"))
                        {
                            chunk = chunk.Substring(0, chunk.Length - 1);
                            leftToYield.Add("[[PERIOD]]");
                        }
                        if (chunk.EndsWith(","))
                        {
                            chunk = chunk.Substring(0, chunk.Length - 1);
                            leftToYield.Insert(0, "[[COMMA]]");
                        }
                        if (chunk.StartsWith("‘"))
                        {
                            chunk = chunk.Substring(1);
                        }
                        if (chunk.StartsWith("("))
                        {
                            chunk = chunk.Substring(1);
                        }

                        yield return chunk;

                        foreach (string piece in leftToYield)
                            yield return piece;

                        if (position < line.Length)
                        {
                            if (line[position] == ' ')
                            {
                                ++position;
                                yield return "[[SPACE]]";
                            }
                            else if (line[position] == '\r' || line[position] == '\n')
                            {
                                ++position;
                                ++position;
                            }
                        }
                        else
                        {
                            yield return "[[SPACE]]";
                        }
                    }
                }
            }

            yield return "[[END]]";
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
