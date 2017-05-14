#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	output.precision(6);

	int testCaseCount;
	input >> testCaseCount;
	for (int testCaseIndex = 0; testCaseIndex < testCaseCount; ++testCaseIndex)
	{
		output << "Case #" << (testCaseIndex + 1) << ": ";

		int D;
		input >> D;
		int N;
		input >> N;

		double slowestTime = 0;

		for (int horseIndex = 0; horseIndex < N; ++horseIndex)
		{
			int K;
			input >> K;
			int S;
			input >> S;

			double remainingDistance = D - K;
			double hours = remainingDistance / S;
			if (hours > slowestTime)
				slowestTime = hours;

		}

		double speed = D / slowestTime;

		output << fixed << speed << endl;
	}

	return 0;
}
