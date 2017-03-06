#include "stdafx.h"

#include "lclmbkquicksort\quicksort.h"

#include <fstream>
#include <iostream>>
#include <list>
#include <vector>
#include <Windows.h>

int main(int argc, char** argv)
{
	std::list<int> datalist;
	{
		std::ifstream stream;
		stream.open(argv[1]);

		while (!stream.eof())
		{
			int v;
			stream >> v;
			datalist.push_back(v);
		}

		stream.close();
	}
	std::vector<int> data(datalist.begin(), datalist.end());

	long before = GetTickCount();

	if (argc == 2)
		lcl::mbk::algorithms::quickSort(data);
	else if (argc == 3 && argv[2] == std::string("n"))
		lcl::mbk::algorithms::quickSort_nonRecursive(data);
	else if (argc == 3 && argv[2] == std::string("t"))
		lcl::mbk::algorithms::quickSort_tailRecursive(data);

	long after = GetTickCount();

	for (size_t i = 1; i < data.size(); ++i)
	{
		if (data[i - 1] > data[i])
		{
			std::cerr << "Incorrect sorting!" << std::endl;
			return 1;
		}
	}

	std::cout << "Time: " << (after - before) << " ticks" << std::endl;
    return 0;
}

