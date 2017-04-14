package codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Pancakes {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("system.in"));
		int cases = Integer.parseInt(sc.nextLine());
		
		List<String> lines = new ArrayList<String>();
		for (int i=0; i<cases; i++) {
			lines.add(sc.nextLine());
		}
		sc.close();
		
		PrintWriter pw = new PrintWriter("system.out");
		for (int i=0; i<cases; i++) {
			String solution = solve(lines.get(i));
			pw.println(String.format("Case #%d: %s", i+1, solution));
		}
		pw.close();
		
	}

	private static String solve(String string) {
		String[] parts = string.split(" ");
		
		String _conf = parts[0];
		int K = Integer.parseInt(parts[1]);
		boolean[] conf = new boolean[_conf.length()];
		for (int i=0; i<_conf.length(); i++) {
			conf[i] = _conf.charAt(i) == '+';
		}
		
		return solve(conf, K);
	}
	
	private static int flips = 0;
	private static String solve(boolean[] conf, int k) {
		flips = 0;
		int nextIndex = 0;
		
		while (nextIndex >= 0) {
			nextIndex = solve(conf, k, nextIndex);
			if (nextIndex == -1) {
				return "IMPOSSIBLE";
			} else if (nextIndex == -2) {
				return "" + flips;
			}
		}
		
		return "?";
	}


	
	private static int solve(boolean[] conf, int k, int idx) {
		for (int i=idx; i<conf.length; i++) {
			if (conf[i]) {
				// good
			} else {
				// are we too close to the end?
				if (i+k-1 < conf.length) {
					// lets flip
					flip(conf, i, k);
					flips++;
					return i;
				} else {
					// Unsolvable
					return -1;
				}
				
			}
		}
		
		// Solved.
		return -2;
	}

	private static void flip(boolean[] conf, int idx, int k) {
		for (int i=idx; i<(idx+k); i++) {
			conf[i] = !conf[i];
		}
	}

}
