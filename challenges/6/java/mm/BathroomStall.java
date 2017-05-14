package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BathroomStall {

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
			String parts[] = lines.get(i).split(" ");
			int N = Integer.parseInt(parts[0]);
			int K = Integer.parseInt(parts[1]);
			String solution = solve(N,K);
			pw.println(String.format("Case #%d: %s", i+1, solution));
		}
		pw.close();
		
	}
	
	public static String solve(int N, int K) {
		double c = calc(N,K);
		double whole = Math.floor(c);
		double decimal = c-whole;
		
		double min = whole;
		double max = whole;
		
		if (decimal >= 0.5) {
			max++;
		}
		
		return (int)max + " " + (int)min;
	}

	
	
	public static double calc(int N, int K) {
		int stalls = N-K;
		
		double howOftenItHalves = Math.floor(log2(K));
		double halfs = Math.pow(0.5, 1+howOftenItHalves);
		
		return stalls * halfs;
	}



	public static double log2(double i) {
		return Math.log(i) / Math.log(2);
	}
}
