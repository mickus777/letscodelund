#include <fstream>
#include <string>
#include <iostream>

using namespace std;

string clean(string tidy) {
	if (tidy[0] == '0') {
		return clean(tidy.substr(1));
	}
	else {
		return tidy;
	}
}

string lastTidy(string number) {
	if (number.size() == 1) {
		return number;
	}
	else {
		string str = lastTidy(number.substr(1));

		if (str[0] < number[0]) {
			return string(1, number[0] - 1) + string(str.size(), '9');
		}
		else {
			return string(1, number[0]) + str;
		}
	}
}

void handleCase(int caseNumber, const string& number) {
	cout << "Case #" << caseNumber << ": " << clean(lastTidy(number)) << endl;
}

int main(int argc, char** argv) {

	ifstream input(argv[1]);

	int testCases;

	input >> testCases;

	for (int i = 0; i < testCases; ++i) {
		string N;
		input >> N;

		handleCase(i + 1, N);
	}

	return EXIT_SUCCESS;
}