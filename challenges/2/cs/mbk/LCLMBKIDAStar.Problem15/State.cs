using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LCLMBKIDAStar.Problem15
{
    public class State : IDAStar.State
    {
        public double Heuristic { get; private set; }
        public double CostToReach { get { return PreviousStates.Count; } }

        public List<int> Board { get; private set; }

        public List<State> PreviousStates { get; private set; }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public State(List<int> board)
        {
            Board = new List<int>(board);
            Heuristic = TotalManhattanDistance(this);
            PreviousStates = new List<State>();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public double StepCost(IDAStar.State other)
        {
            return 1;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public IEnumerable<IDAStar.State> Successors()
        {
            int hole = FindValue(15);

            List<State> states = new List<State>();
            AddMoveIfPossible(states, hole, -1, 0);
            AddMoveIfPossible(states, hole, 1, 0);
            AddMoveIfPossible(states, hole, 0, -1);
            AddMoveIfPossible(states, hole, 0, 1);

            return states.OrderBy(s => s.Heuristic).Cast<IDAStar.State>();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private void AddMoveIfPossible(List<State> states, int hole, int deltaX, int deltaY)
        {
            if (hole < 4 && deltaY < 0 || hole > 11 && deltaY > 0 || (hole % 4) == 0 && deltaX < 0 || (hole % 4) == 3 && deltaX > 0)
                return;

            int nextHole = hole + deltaX + 4 * deltaY;

            State move = Move(hole, nextHole);

            foreach (State previousState in PreviousStates)
                if (move.Equals(previousState))
                    return;

            states.Add(move);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private State Move(int source, int target)
        {
            List<int> newBoard = new List<int>(Board);

            int value = newBoard[source];
            newBoard[source] = newBoard[target];
            newBoard[target] = value;

            State newState = new State(newBoard);
            newState.PreviousStates = new List<State>(PreviousStates);
            newState.PreviousStates.Add(this);

            return newState;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private int FindValue(int value)
        {
            return Board.IndexOf(value);
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static int TotalManhattanDistance(State state)
        {
            int total = 0;

            for (int i = 0; i < 16; ++i)
                if (state.Board[i] != 15)
                    total += ManhattanDistance(state.Board[i], i);

            return total;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static int ManhattanDistance(int source, int target)
        {
            return Math.Abs(source / 4 - target / 4) + Math.Abs((source % 4) - (target % 4));
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public override string ToString()
        {
            return "(" + string.Join(", ", Board.ToArray()) + ")";
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;

            if (!(obj is State))
                return false;

            State state = (State)obj;

            for (int i = 0; i < 16; ++i)
                if (state.Board[i] != Board[i])
                    return false;

            return true;
        }
    }
}
