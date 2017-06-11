package fifteen;

import java.util.HashSet;
import java.util.Set;

/**
 * General IDA* solver
 */
public class IdaStarSolver<StateType> {
	
	// Callback stuff.
	public static interface IdaStarContext<StateType> {
		public double h(StateType o);
		public boolean is_goal(StateType node);
		public StateType[] successors(StateType node);
		public double cost(StateType node, StateType succ);
		
		public void enter(StateType node);
		public void leave();
	}
	
	
	private static final double NOT_FOUND = -2;
	private static final double FOUND = -1;
	private static final double INF = Double.MAX_VALUE;
	
	public IdaStarSolver(IdaStarContext<StateType> context) {
		this.context = context;
	}
	
	private IdaStarContext<StateType> context;
	private Set<Object> visited = new HashSet<Object>();

	public double ida_star(StateType root) {
		double bound = context.h(root);
		while (true) {
			visited.add(root);
			double t = search(root, 0, bound);
			if (t == FOUND) return bound;
			if (t == INF) return NOT_FOUND;
			bound = t;
		}
	}
	
	
	private double search(StateType node, double g, double bound) {
		double f = g + context.h(node);
		if (f > bound) return f;
		if (context.is_goal(node)) return FOUND;
		double min = INF;
		for (StateType succ : context.successors(node)) {
			if (succ == null) continue;
			if (visited.contains(succ)) {
				continue;
			}
			
			context.enter(succ);
			visited.add(succ);
			double t = search(succ, g + context.cost(node, succ), bound);
			if (t == FOUND) {
				return FOUND;
			}
			visited.remove(succ);
			context.leave();
			
			if (t < min) min = t;
		}
		return min;
	}
}