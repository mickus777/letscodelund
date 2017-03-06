using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LCLMBKIDAStar
{
    public class IDAStar
    {
        ///////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////
        public interface State
        {
            double Heuristic { get; }
            double CostToReach { get; }

            double StepCost(State other);
            IEnumerable<State> Successors();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public static State Search(State root)
        {
            double bound = root.Heuristic;
            while (true)
            {
                Tuple<double, State> state = Search(root, bound);
                if (state.Item2.Heuristic == 0)
                    return state.Item2;
                if (state.Item1 == double.MaxValue)
                    throw new Exception("No solution!");
                bound = state.Item1;
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static Tuple<double, State> Search(State state, double bound)
        {
            double costToReachEnd = state.CostToReach + state.Heuristic;
            if (costToReachEnd > bound)
                return new Tuple<double, State>(costToReachEnd, state);

            if (state.Heuristic == 0)
                return new Tuple<double, State>(costToReachEnd, state);

            double min = double.MaxValue;
            foreach (State succ in state.Successors())
            {
                Tuple<double, State> foundState = Search(succ, bound);
                if (foundState.Item2.Heuristic == 0)
                    return foundState;
                if (foundState.Item1 < min)
                    min = foundState.Item1;
            }

            return new Tuple<double, State>(min, state);
        }
    }
}
