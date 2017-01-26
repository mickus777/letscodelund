#ifndef INC_LCL_MBK_ALGORITHMS_QUICKSORT_H
#define INC_LCL_MBK_ALGORITHMS_QUICKSORT_H

#include <vector>

namespace lcl
{
	namespace mbk
	{
		namespace algorithms
		{
			template<typename T>
			void swap(std::vector<T>& data, const size_t i1, const size_t i2)
			{
				T t = data[i1];
				data[i1] = data[i2];
				data[i2] = t;
			}

			template<typename T>
			void quickSort(std::vector<T>& data, const size_t start, const size_t end)
			{
				if (start >= end)
					return;

				size_t pivot = start;

				for (size_t i = start + 1; i <= end; ++i)
				{
					if (data[i] < data[pivot])
					{
						if (pivot + 1 != i)
							swap(data, pivot, pivot + 1);
						swap(data, pivot, i);
						pivot += 1;
					}
				}

				if (pivot > start)
					quickSort(data, start, pivot - 1);
				if (pivot < end)
					quickSort(data, pivot + 1, end);
			}

			template<typename T>
			void quickSort(std::vector<T>& data)
			{
				quickSort(data, 0, data.size() - 1);
			}
		}
	}
}

#endif

