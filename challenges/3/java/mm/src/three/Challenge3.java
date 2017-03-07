package three;

import java.io.IOException;
import java.util.List;
import java.util.Stack;

public class Challenge3 {
	public static void main(String[] args) throws IOException {
		BusProblem busProblem = BusProblem.read("../../data/1000_666_all_individuals.txt");
		
		System.out.println("Bus size: " + busProblem.busSize);
		System.out.println(busProblem.groups.size() + " groups: " + busProblem.groups);
		
		search(0, busProblem.groups, busProblem.busSize);
		
		System.out.println();
		if (best > -1) {
			System.out.println("Best solution: " + best + " person"+(best>1?"s":"")+" (" + bestStack + ")");
		} else {
			System.err.println("No solution. No one can go! ");
		}
	}
	
	private static Stack<Group> currentStack = new Stack<Group>();
	private static Stack<Group> bestStack = new Stack<Group>();
	private static int best = -1;
	
	
	
	private static int search(int onboard, List<Group> groups, int busSize) {
		
		if (onboard == busSize) {
			return busSize;
		}
		if (onboard > busSize) {
			return -1;
		}
		
		int maxPossible = onboard;
		for (Group g : groups) {
			maxPossible += g.size;
		}
		if (maxPossible < best) {
			return -1;
		}
		
		int max = 0;
		for (int i=0; i<groups.size(); i++) {
			Group group = groups.get(i);
			
			List<Group> subGroups = groups.subList(i+1, groups.size());
			int tryToBoard = onboard + group.size;
			
			currentStack.push(group);
			int res= search(tryToBoard, subGroups, busSize);
			if (res > -1) {
				if (tryToBoard > best) {
					best = tryToBoard;
					bestStack = new Stack<Group>();
					bestStack.addAll(currentStack);
				}
				
				if (res == busSize) {
					return res;
				}
				if (res > max) {
					max = res;
				}
				
			}
			currentStack.pop();
		}
		
		return max;
	}

}
