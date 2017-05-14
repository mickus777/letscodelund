package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Tidy {
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
			byte[] b = lines.get(i).getBytes();
			tidy(b, 1);
			pw.println(String.format("Case #%d: %s", i+1, new BigInteger(new String(b)).toString()));
		}
		pw.close();
		
	}

	private static boolean tidy(byte[] b, int i) {
		if (i == b.length) {
			return false;
		}
		
		byte c = b[i];
		byte c1 = b[i-1];
		
		boolean didTidy = false;
		if (c >= c1) {
			didTidy = tidy(b, i+1);
			c = b[i];
			c1 = b[i-1];
		}
		if (c < c1) {
			b[i-1]--;
			for (int j=i; j<b.length; j++) {
				b[j] = '0'+9;
			}
			didTidy = true;
		}
		return didTidy;
	}
}
