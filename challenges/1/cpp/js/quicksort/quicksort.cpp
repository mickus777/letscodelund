#include <cstdlib>
#include <cassert>
#include <vector>
#include "quicksort.h"

int main(void) {

	auto array1 = std::vector<int>{ 3, 8, 1, 2, 1, 9, 0 };
	auto array2 = std::vector<int>{ 1 };
	auto array3 = std::vector<int>{ 1, 1 };
	auto array4 = std::vector<int>{ 1, 1, 1 };

	quicksort(array1.begin(), array1.end());
	quicksort(array2.begin(), array2.end());
	quicksort(array3.begin(), array3.end());
	quicksort(array4.begin(), array4.end());

	using std::is_sorted;

	assert(is_sorted(array1.begin(), array1.end()));
	assert(is_sorted(array2.begin(), array2.end()));
	assert(is_sorted(array3.begin(), array3.end()));
	assert(is_sorted(array4.begin(), array4.end()));

	return EXIT_SUCCESS;
}