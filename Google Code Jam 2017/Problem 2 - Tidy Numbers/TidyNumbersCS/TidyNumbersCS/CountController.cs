using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TidyNumbersCS
{
    public class CountController
    {
        public CountController() { }

        public long Control(long input)
        {
            while (!integerIsTidy(divideInteger(input)))
                input = input - 1;


            return input;
        }

        public int[] divideInteger(long input)
        {
            char[] charDiv = input.ToString().ToCharArray();
            int[] intDiv = new int[charDiv.Length];
            for (int i = 0; i < charDiv.Length; i++)
                intDiv[i] = (int)Char.GetNumericValue(charDiv[i]);
            return intDiv;
        }

        public bool integerIsTidy(int[] intDiv)
        {
            for (int i = 1; i < intDiv.Length; i++)
                if (intDiv[i] < intDiv[i - 1])
                    return false;
            return true;
        }

    }
}
