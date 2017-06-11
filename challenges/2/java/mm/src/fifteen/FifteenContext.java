package fifteen;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;

import fifteen.IdaStarSolver.IdaStarContext;

public class FifteenContext implements IdaStarContext<State> {
	private static Comparator<State> comparator = new Comparator<State>(){
		@Override
		public int compare(State s1, State s2) {
			return s1.cost - s2.cost;
		}
	};
	

	public int moves = 0;
	public Stack<Character> stack = new Stack<Character>();
	public int statesSearched = 0;
	
	
	@Override
	public double h(State state) {
		// Already precalculated
		return state.cost;
	}

	@Override
	public boolean is_goal(State state) {
		for (int i=0; i<16; i++) {
			int v = state.board[i];
			if (v-1 != i) {
				return false;
			}
		}
		return true;
	}

	@Override
	public State[] successors(State state) {
		State down = state.down();
		State up = state.up();
		State left = state.left();
		State right = state.right();
		
		int count = 0;
		if (down != null) count++;
		if (up != null) count++;
		if (left != null) count++;
		if (right != null) count++;
		
		State[] succs = new State[count];
		int i=0;
		if (down != null) { succs[i] = down; i++; }
		if (up != null) { succs[i] = up; i++; }
		if (left != null) { succs[i] = left; i++; }
		if (right != null) { succs[i] = right; i++; }
		
		Arrays.sort(succs, comparator);
		
		return succs;
	}

	@Override
	public double cost(State node, State succ) {
		return 1;
	}

	@Override
	public void enter(State state) {
		moves++;
		statesSearched++;
		stack.push(state.move);
	}

	@Override
	public void leave() {
		moves--;
		stack.pop();
	}
}
