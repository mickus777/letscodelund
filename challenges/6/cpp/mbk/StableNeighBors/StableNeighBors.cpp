#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string indexToColor(size_t index)
{
	switch (index)
	{
	case 0: return "R";
	case 1: return "O";
	case 2: return "Y";
	case 3: return "G";
	case 4: return "B";
	case 5: return "V";
	}
}

bool stepDown(vector<int>& unicorns, size_t last, size_t remaining, size_t start, string& path)
{
	for (size_t i = 2; i < 5; ++i)
	{
		size_t pos = (last + i) % 6;

		if (unicorns[pos] > 0)
		{
			if (remaining == 1)
			{
				if (pos < start && pos + 1 < start || start < pos && start + 1 < pos)
				{
					path = indexToColor(pos);
					return true;
				}
				else
				{
					return false;
				}
			}

			--unicorns[pos];
			bool result = stepDown(unicorns, pos, remaining - 1, start, path);
			++unicorns[pos];

			if (path.size() > 0)
			{
				path = indexToColor(pos) + path;
				return true;
			}
		}
	}

	return false;
}

int findGreatest(vector<int>& collections)
{
	int count = 0;
	int greatest = collections[0];
	for (int i = 1; i < 6; ++i)
	{
		if (collections[i] > greatest)
		{
			count = i;
			greatest = collections[i];
		}
	}

	return count;
}

int distance(int index, int target)
{
	return (target + 6 - index) % 6;
}

int findGreatest(vector<int>& collections, int around, int bias)
{
	int before = (around + 5) % 6;
	int after = (around + 1) % 6;

	int valueBefore = collections[before];
	int value = collections[around];
	int valueAfter = collections[after];

	if (valueBefore > value && valueBefore > valueAfter)
		return before;
	if (value > valueBefore && value > valueAfter)
		return around;
	if (valueAfter > valueBefore && valueAfter > value)
		return after;
	
	if (valueBefore == value)
	{
		if (distance(before, bias) < distance(around, bias))
			return before;
		else
			return around;
	}
	else if (value == valueAfter)
	{
		if (distance(around, bias) < distance(after, bias))
			return around;
		else
			return after;
	}
	else
	{
		if (distance(before, bias) < distance(after, bias))
			return before;
		else
			return after;
	}
}

int main(int argc, char** argv)
{
	ifstream input(argv[1]);
	ofstream output(argv[2]);

	int testCaseCount;
	input >> testCaseCount;
	for (int testCaseIndex = 0; testCaseIndex < testCaseCount; ++testCaseIndex)
	{
		output << "Case #" << (testCaseIndex + 1) << ": ";

		int total;
		input >> total;

		vector<int> unicorns(6);
		for (size_t i = 0; i < 6; ++i)
		{
			int count;
			input >> count;
			unicorns[i] = count;
		}
		vector<int> collections(6);
		for (int i = 0; i < 6; ++i)
		{
			collections[i] = unicorns[i];
			if (collections[i] > 0)
			{
				collections[i] += unicorns[(i + 1) % 6];
				collections[i] += unicorns[(i + 5) % 6];
			}
		}

		int start = findGreatest(collections);
		--unicorns[start];
		if (unicorns[start] == 0)
			collections[start] = 0;
		else
			--collections[start];
		string path = indexToColor(start);
		--total;

		int last = start;
		while (total > 1)
		{
			int next = findGreatest(collections, (last + 3) % 6, start);
			--unicorns[next];
			if (unicorns[next] == 0)
				collections[next] = 0;
			else
				--collections[next];
			path += indexToColor(next);
			--total;
			last = next;
		}

		int terminator = findGreatest(collections);
		if (distance(terminator, start) < 2)
			output << "IMPOSSIBLE" << endl;
		else
			output << indexToColor(terminator) << path << endl;
	}

	return 0;
}

