#include <algorithm>
#include <fstream>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

int calculateDistance(string pancakes)
{
	int distance = 0;

	for (size_t i = 0; i < pancakes.size(); ++i)
		if (pancakes[i] == '-')
			++distance;

	return distance;
}

string flip(string pancakes, size_t position, size_t flipperWidth)
{
	string newPancakes = pancakes;

	for (size_t i = position; i < position + flipperWidth; ++i)
		newPancakes[i] = pancakes[i] == '+' ? '-' : '+';

	return newPancakes;
}

struct State
{
	string _pancakes;
	int _flipCount;
	int _distance;

	State(string p, int c) : _pancakes(p), _flipCount(c), _distance(calculateDistance(_pancakes)) {} 
};

void insertSorted(list<State*>& pancakesSet, State* state)
{
	for (list<State*>::iterator it = pancakesSet.begin(); it != pancakesSet.end(); ++it)
	{
		if ((*it)->_distance + (*it)->_flipCount > state->_distance + state->_flipCount)
		{
			pancakesSet.insert(it, state);
			return;
		}
	}

	pancakesSet.push_back(state);
}

string trim(string pancakes)
{
	size_t first = pancakes.find('-');
	if (first == string::npos)
		return pancakes;
	size_t last = pancakes.rfind('-');

	return pancakes.substr(first, last - first + 1);
}

vector<bool> parse(const string& pancakes)
{
	vector<bool> result(pancakes.size(), false);

	for (size_t i = 0; i < pancakes.size(); ++i)
		result[i] = pancakes[i] == '+';

	return result;
}

int correct(vector<bool>& pancakes, size_t flipperWidth)
{
	size_t first = pancakes.size();
	for (size_t i = 0; i < pancakes.size(); ++i)
	{
		if (!pancakes[i])
		{
			first = i;
			break;
		}
	}

	if (first == pancakes.size())
		return 0;

	size_t last = first;
	for (size_t i = pancakes.size() - 1; i > first; --i)
	{
		if (!pancakes[i])
		{
			last = i;
			break;
		}
	}

	int flipCount = 0;
	while (true)
	{
		if (last - first < flipperWidth - 1)
			return -1;

		++flipCount;
		for (size_t i = 0; i < flipperWidth; ++i)
			pancakes[first + i] = !pancakes[first + i];

		while (first < pancakes.size() && pancakes[first])
			++first;

		if (first >= pancakes.size())
			return flipCount;
	}
}

int findLeastFlipCount(string pancakes, size_t flipperWidth)
{
	list<State*> remaining;
	remaining.push_back(new State(pancakes, 0));
	set<string> visited;

	while (remaining.size() > 0)
	{
		State* state = remaining.front();
		remaining.pop_front();

		if (state->_distance == 0)
		{
			int count = state->_flipCount;
			delete state;
			return count;
		}

		visited.insert(state->_pancakes);
		for (size_t i = 0; i <= state->_pancakes.size() - flipperWidth; ++i)
		{
			string newPancakes = flip(state->_pancakes, i, flipperWidth);
			if (visited.find(newPancakes) != visited.end())
				continue;

			insertSorted(remaining, new State(newPancakes, state->_flipCount + 1));
		}

		delete state;
	}

	return -1;
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

		string pancakes;
		input >> pancakes;
		int flipperWidth;
		input >> flipperWidth;

		int result = correct(parse(pancakes), flipperWidth);
//		int result = findLeastFlipCount(trim(pancakes), flipperWidth);
		if (result > -1)
			output << result;
		else
			output << "IMPOSSIBLE";

		output << endl;
	}

	return 0;
}
