package three;

import java.util.ArrayList;
import java.util.List;

public class Group {
	public final int size;
	public List<Integer> personIndex = new ArrayList<Integer>();
	
	public Group(int size) {
		this.size = size;
	}
	
	public String toString() {
		return size + " person" + (size>1?"s":"") + ":" + personIndex + "";
	}
}
