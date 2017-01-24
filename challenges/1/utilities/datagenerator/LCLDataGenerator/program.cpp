#include "stdafx.h"

#include <fstream>
#include <time.h>

int main(int argc, char** argv)
{
	srand(time(0));

	std::ofstream stream(argv[1]);

	int count = atoi(argv[2]);

	for (int i = 0; i < count; ++i)
		stream << static_cast<unsigned>(rand()) << std::endl;

    return 0;
}

