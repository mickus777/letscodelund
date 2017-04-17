using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TidyNumbersCS
{
    public class Controller
    {
        public Controller(){}

        public long Control(long input)
        {
            int[] intDiv = divideInteger(input);

            while (!integerIsTidy(intDiv))
                iterate(intDiv);

            return joinInteger(intDiv);
        }
        
        public void iterate(int[] intDiv)
        {
            for (int i = intDiv.Length - 1; i > 0; i--)
            {
                if (!pairIsTidy(intDiv[i-1], intDiv[i]))
                    lowerToNine(intDiv, i-1, i);
            }
        }

        //firstPosition is the leftmost of the two values 
        //lowerToNine decreases leftmost value with one and sets the rest to nine
        public void lowerToNine(int[] intDiv, int firstPosition, int secondPosition)
        {
            intDiv[firstPosition] = intDiv[firstPosition] - 1;
            for (int i = secondPosition; i < intDiv.Length; i++)
                intDiv[i] = 9;
        }

        public int[] divideInteger(long input)
        {
            char[] charDiv = input.ToString().ToCharArray();
            int[] intDiv = new int[charDiv.Length];
            for (int i = 0; i < charDiv.Length; i++)
                intDiv[i] = (int)Char.GetNumericValue(charDiv[i]);
            return intDiv;
        }

        public bool pairIsTidy(int firstValue, int secondValue)
        {
            if (secondValue < firstValue)
                return false;
            return true;
        }

        public bool integerIsTidy(int[] intDiv)
        {
            for (int i = 1; i < intDiv.Length; i++)
                if (intDiv[i] < intDiv[i - 1])
                    return false;
            return true;
        }

        public long joinInteger(int[] intDiv)
        {
            string tempStr = "";
            for (int i = 0; i < intDiv.Length; i++)
                tempStr += intDiv[i].ToString();
            return Int64.Parse(tempStr);
        }

    }
}
