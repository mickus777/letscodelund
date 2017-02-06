#ifndef INC_LCL_JS_QUICKSORT_H
#define INC_LCL_JS_QUICKSORT_H

#include <iterator>
#include <algorithm>
#include <array>

// Smallest array to sort with quicksort
const auto QS_THRESHOLD = 20;

// For sorting small arrays
template<class RandomAccessIterator>
void insertionsort(RandomAccessIterator first, RandomAccessIterator last) {
	for (auto itr = first + 1; itr < last; ++itr) {
		for (auto jtr = itr; jtr > first && *(jtr - 1) > *jtr; --jtr) {
			std::swap(*jtr, *(jtr - 1));
		}
	}
}

template<class RandomAccessIterator>
RandomAccessIterator select_pivot(RandomAccessIterator first, RandomAccessIterator last) {
	static_assert(QS_THRESHOLD >= 3, "Selecting the median of 3 as pivot");

	auto middle = first + std::distance(first, last) / 2;
	std::array<decltype(first), 3> positions = { first, middle, last };

	insertionsort(positions.begin(), positions.end());

	return positions[1];
}

template<class RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last) {
	if (std::distance(first, last) >= QS_THRESHOLD) {
		auto pivot = *select_pivot(first, last);

		auto left_pos = first;
		auto right_pos = last - 1;

		while (true) {
			while (*left_pos < pivot) {
				++left_pos;
			}

			while (pivot < *right_pos) {
				--right_pos;
			}

			if (left_pos < right_pos) {
				std::swap(*left_pos, *right_pos);
				++left_pos;
				--right_pos;
			}
			else {
				break;
			}
		}

		quicksort(first, right_pos);
		quicksort(right_pos + 1, last);
	}
	else {
		insertionsort(first, last);
	}
}

#endif // INC_LCL_JS_QUICKSORT_H
