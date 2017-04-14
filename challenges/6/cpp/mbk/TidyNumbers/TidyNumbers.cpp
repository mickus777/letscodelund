#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	ifstream input(argv[1]);
	ofstream output(argv[2]);

	int testCaseCount;
	input >> testCaseCount;
	for (int testCaseIndex = 0; testCaseIndex < testCaseCount; ++testCaseIndex)
	{
		output << "Case #" << (testCaseIndex + 1) << ": ";

		string number;
		input >> number;

		char currentDigit = number[0];
		size_t firstSameDigit = 0;
		bool tidiedNumber = false;
		for (size_t digitIndex = 1; digitIndex < number.size(); ++digitIndex)
		{
			if (number[digitIndex] < currentDigit)
			{
				tidiedNumber = true;

				for (size_t i = 0; i < firstSameDigit; ++i)
					output << number[i];

				--currentDigit;
				if (currentDigit != '0' || firstSameDigit > 0)
					output << currentDigit;

				for (size_t i = firstSameDigit + 1; i < number.size(); ++i)
					output << '9';

				break;
			}
			else if (number[digitIndex] > currentDigit)
			{
				currentDigit = number[digitIndex];
				firstSameDigit = digitIndex;
			}
		}

		if (!tidiedNumber)
			output << number;

		output << endl;
	}

    return 0;
}

