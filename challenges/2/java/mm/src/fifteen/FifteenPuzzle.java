package fifteen;

import java.io.IOException;

public class FifteenPuzzle {
	
	public static void main(String[] args) throws IOException {
		// Warmup JVM so measuring is more correct
		long warmupTime = warmup();
		
		System.out.println("Running after warming up for "+warmupTime+" ms ...");
		
		State rootState = new State(FifteenUtil.readPuzzleState("puzzles/47.txt"));
		if (!FifteenUtil.isSolvable(rootState.board)) {
			System.err.println("This puzzle is unsolvable!");
		} else {
			FifteenContext context = new FifteenContext();
			
			System.out.println("Initial estimate: " + context.h(rootState));
			
			IdaStarSolver<State> solver = new IdaStarSolver<State>(context);
			
			long t1 = System.currentTimeMillis();
			solver.ida_star(rootState);
			long t2 = System.currentTimeMillis();
			
			System.out.println();
			
			System.out.println("Finished after "+ (t2-t1) + " ms");
			System.out.println("States searched: " + context.statesSearched);
			System.out.println("Moves: " + context.moves);
			System.out.println("Solution: " + context.stack);
		}
	}
	
	private static long warmup() throws IOException {
		int[] board = FifteenUtil.readPuzzleState("puzzles/28.txt");
		
		System.out.println("Warming up..");
		long t1 = System.currentTimeMillis();
		for (int i=0; i<1000; i++) {
			State state = new State(board);
			IdaStarSolver<State> solver = new IdaStarSolver<State>(new FifteenContext());
			solver.ida_star(state);
		}
		long t2 = System.currentTimeMillis();
		return t2-t1;
	}
	
	
}
