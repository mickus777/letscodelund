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

		unsigned long long stalls;
		input >> stalls;
		unsigned long long people;
		input >> people;

		unsigned long long comparator = 2;
		unsigned long long path = people;

		while (people >= comparator)
		{
			if (path % 2 == 1)
				stalls -= 1;
			stalls /= 2;

			path >>= 1;

			comparator *= 2;
		}

		output << (stalls / 2) << " " << ((stalls - 1) / 2) << endl;
	}

	return 0;
}

