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

        private int Size;

        ///////////////////////////////////////////////////////////////////////////////////////////
        public State(List<int> board)
        {
            Board = new List<int>(board);
            Size = (int)Math.Sqrt(board.Count);
            Heuristic = TotalManhattanDistance(this, Size);
            PreviousStates = new List<State>();
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public double StepCost(IDAStar.State other)
        {
            return 1;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public bool HasSolution()
        {
            int parity = 0;

            for (int i = 0; i < Size * Size; ++i)
                if (Board[i] != (Size * Size - 1))
                    for (int j = i + 1; j < Size * Size; ++j)
                        if (Board[j] != (Size * Size - 1))
                            if (Board[j] < Board[i])
                                ++parity;

            parity += FindValue(Size * Size - 1) / 4 + 1;

            return parity % 2 == 0;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        public IEnumerable<IDAStar.State> Successors()
        {
            int hole = FindValue(Size * Size - 1);

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
            if (hole < Size && deltaY < 0 || 
                hole > (Size * (Size - 1) - 1) && deltaY > 0 || 
                (hole % Size) == 0 && deltaX < 0 || 
                (hole % Size) == (Size - 1) && deltaX > 0)
                return;

            int nextHole = hole + deltaX + Size * deltaY;

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
        private static int TotalManhattanDistance(State state, int size)
        {
            int total = 0;

            for (int i = 0; i < size * size; ++i)
                if (state.Board[i] != (size * size - 1))
                    total += ManhattanDistance(state.Board[i], i, size);

            return total;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        private static int ManhattanDistance(int source, int target, int size)
        {
            return Math.Abs(source / size - target / size) + 
                   Math.Abs((source % size) - (target % size));
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

            for (int i = 0; i < Size * Size; ++i)
                if (state.Board[i] != Board[i])
                    return false;

            return true;
        }
    }
}
