package fifteen;

import java.util.Arrays;

public class State {
	
	public final int cost; // Calculated in constructor
	private final int hashCode; // Calculated in constructor
	
	private final int empty_x, empty_y; // Empty spot
	public final char move; // The move that got us to this state, 'd','u','l','r'
	
	public int[] board;

	public State(int[] board) {
		int _y = 0;
		int _x = 0;
		for (int i=0; i<16; i++) {
			if (board[i] == 16) {
				_y = i / 4 ;
				_x = i % 4;
				break;
			}
		}
		this.board = board;
		this.move = ' ';
		this.empty_x = _x;
		this.empty_y = _y;
		this.cost = FifteenUtil.cost(board);
		this.hashCode = Arrays.hashCode(board);
	}
	
	public State(int[] board, int empty_x, int empty_y, char move) {
		this.board = board;
		this.empty_x = empty_x;
		this.empty_y = empty_y;
		this.move = move;
		
		this.cost = FifteenUtil.cost(board);
		this.hashCode = Arrays.hashCode(board);
	}

	
	public State down() {
		return moveX(empty_x, empty_y, empty_x, empty_y+1, 'd');
	}
	public State up() {
		return moveX(empty_x, empty_y, empty_x, empty_y-1, 'u');
	}
	public State left() {
		return moveX(empty_x, empty_y, empty_x-1, empty_y, 'l');
	}
	public State right() {
		return moveX(empty_x, empty_y, empty_x+1, empty_y, 'r');
	}

	private State moveX(int fromx, int fromy, int tox, int toy, char move) {
		if (tox >= 0 && tox <= 3 
				&& toy >= 0 && toy <= 3) {
			
			int[] newboard = new int[16];
			System.arraycopy(board, 0, newboard, 0, 16);
			
			int fromIndex = fromy*4+fromx;
			int toIndex = toy*4+tox;
			
			newboard[fromIndex] = newboard[toIndex];
			newboard[toIndex] = 16;
			
			return new State(newboard, tox, toy, move);
		} else {
			return null;
		}
	}
	
	public String toString() {
		String s = "";
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				int a = board[i*4 + j];
				
				String v = (a<10?" ":"") + a;
				s += v + " ";
			}
			s += "\n";
		}
		return s;
	}

	
	public int hashCode() {
		return hashCode;
	}
	public boolean equals(Object o) {
		if (o instanceof State) {
			int[] other = ((State)o).board;
			return Arrays.equals(board, other);
		} else {
			return false;
		}
	}
}