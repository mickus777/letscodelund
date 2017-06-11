package fifteen;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FifteenUtil {
	public static boolean isSolvable(int[] board) {
		int xrow = -1;
		int inversions = 0;
		for (int i=0; i<16; i++) {
			int v = board[i];
			if (v == 16) { // X
				xrow = i / 4;
			} else {
				for (int j=0; j<i; j++) {
					int v2 = board[j];
					if (v2 != 16) {
						if (v2 > v) {
							inversions++;
						}
					}
				}
			}
		}
		
		// Make it 1-based, from bottom
		xrow = 4-xrow;
		
		// Only one of xrow or inversions may be even/odd
		return xrow%2 == 0 ^ inversions%2==0;
	}
	
	public static int[] readPuzzleState(String string) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(string));
		String line=null;
		int[] board = new int[16];
		
		int i=0;
		while ( (line=reader.readLine()) != null) {
			String[] numbers = line.trim().split("\\s+");
			board[i+0] = parseInt(numbers[0]);
			board[i+1] = parseInt(numbers[1]);
			board[i+2] = parseInt(numbers[2]);
			board[i+3] = parseInt(numbers[3]);
			i += 4;
		}
		reader.close();
		
		return board;
	}
	private static int parseInt(String string) {
		if (string.equals("x")) {
			return 16;
		}
		return Integer.parseInt(string);
	}

	

	public static int cost(int[] board) {
		return manhattanDist(board) + 2*linearConflicts(board);
	}
	
	private static int manhattanDist(int[] board) {
		int cost = 0;
		for (int row=0; row<4; row++) {
			for (int col=0; col<4; col++) {
				int v = board[row*4+col];
				if (v != 16) {
					int goalRow = (v-1) / 4;
					int goalCol = (v-1) % 4;
					
					cost += Math.abs(goalRow-row) + Math.abs(goalCol-col);
				}
			}
		}
		
		return cost;
	}
	
	// En rad har linear conflict om man måste byta ordning inom raden. T.ex. [3 1 2 4] 
	private static int linearConflicts(int[] board) {
		int rowConflicts=0; 
		int colConflicts = 0;
		
		// Examine rows
		for (int i=0; i<4; i++) {
			int[] fromrow = new int[]{
				board[i*4+0],
				board[i*4+1],
				board[i*4+2],
				board[i*4+3]
			};
			
			// is linear conflict in this row? 
			for (int j=0; j<4; j++) {
				int value = fromrow[j];  //3
				if (value != 16) {
					int valuesRowInGoal = (value-1)/4;
					if (valuesRowInGoal == i) {
						for (int k=j+1; k<4; k++) {
							int value2 = fromrow[k]; // 1
							if (value2 != 16) {
								int value2sRowInGoal = (value2-1)/4;
								if (value2sRowInGoal == i) {
									if (value > value2) {
										rowConflicts++;
									}
								}
							}
						}
					}
				}
			}
		}
		
		// Examine columns
		for (int i=0; i<4; i++) {
			int[] fromcol = new int[]{
				board[ 0+i],
				board[ 4+i],
				board[ 8+i],
				board[12+i],
			};
			
			// is linear conflict in this col? 
			for (int j=0; j<4; j++) {
				int value = fromcol[j];
				if (value != 16) {
					int valuesColInGoal = (value-1) % 4;
					if (valuesColInGoal == i) {
						for (int k=j+1; k<4; k++) {
							int value2 = fromcol[k];
							if (value2 != 16) {
								int value2sColInGoal = (value2-1) % 4;
								if (value2sColInGoal == i) {
									if (value > value2) {
										colConflicts++;
									}
								}
							}
						}
					}
				}
			}
		}
		
		return rowConflicts + colConflicts;
	}
	
}
