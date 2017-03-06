package three;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class BusProblem {
	public final int busSize;
	public final List<Group> groups;

	public BusProblem(int busSize, List<Group> groups) {
		this.busSize = busSize;
		this.groups = groups;
	}

	public static BusProblem read(String filename) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		String line1 = reader.readLine();
		String[] parts = line1.split("\\s+");
		int personCount = Integer.parseInt(parts[0]);
		int busSize = Integer.parseInt(parts[1]);
		
		int nextGroup = 1;
		int[] persons = new int[personCount]; // person -> group
		
		String line2 = reader.readLine();
		parts = line2.split("\\s+");
		
		reader.close();
		
		if (parts.length != personCount) throw new IOException("person count is "+personCount+". parts length is " + parts.length);
		
		for (int i=0; i<personCount; i++) {
			int myIndex = i;
			int friendIndex = Integer.parseInt(parts[i]) - 1;
			
			if (persons[myIndex] == 0) {
				if (persons[friendIndex] == 0) {
					// has no group
					persons[friendIndex] = nextGroup;
					persons[myIndex] = nextGroup;
					nextGroup++;
				} else {
					persons[myIndex] = persons[friendIndex];
				}
			} else {
				persons[friendIndex] = persons[myIndex];
			}
		}
		
		
		int[] groupSizes = new int[nextGroup-1];
		for (int i=0; i<personCount; i++) {
			int group = persons[i];
			groupSizes[group-1]++; 
		}
		
		List<Group> groups = new ArrayList<Group>();
		for (int i=0; i<groupSizes.length; i++) {
			groups.add(new Group(groupSizes[i]));
		}
		for (int i=0; i<personCount; i++) {
			int group = persons[i];
			groups.get(group-1).personIndex.add(i);
		}
		
		Collections.sort(groups, new Comparator<Group>() {
			@Override
			public int compare(Group o1, Group o2) {
				return o2.size - o1.size;
			}
		});
		
		return new BusProblem(busSize, groups);
	}

	
	
}
