#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void invert(string& pancakes, size_t position, size_t K) {
	for (size_t i = position; i < position + K; ++i) {
		if (pancakes[i] == '+') {
			pancakes[i] = '-';
		}
		else {
			pancakes[i] = '+';
		}
	}
}

bool solve(string& pancakes, size_t position, size_t K, size_t& flips) {
	if (position + K == pancakes.size()) {
		for (size_t i = position + 1; i < pancakes.size(); ++i) {
			if (pancakes[i] != pancakes[position]) {
				return false;
			}
		}
		if (pancakes[position] == '+') {
			flips = 0;
		}
		else {
			flips = 1;
		}
		return true;
	}
	else {
		if (pancakes[position] == '+') {
			return solve(pancakes, position + 1, K, flips);
		}
		else {
			invert(pancakes, position, K);
			bool result = solve(pancakes, position + 1, K, flips);
			++flips;
			return result;
		}
	}
}

void handleCase(int caseNumber, const string& pancakes, size_t K) {
	cout << "Case #" << caseNumber << ": ";

	size_t flips = 0;
	string scratch = pancakes;
	if (solve(scratch, 0, K, flips)) {
		cout << flips;
	}
	else {
		cout << "IMPOSSIBLE";
	}

	cout << endl;
}

int main(int argc, char** argv) {

	ifstream input(argv[1]);

	int testCases;

	input >> testCases;

	for (int i = 0; i < testCases; ++i) {
		string pancakes;
		size_t K;

		input >> pancakes >> K;

		handleCase(i + 1, pancakes, K);
	}

	return EXIT_SUCCESS;
}