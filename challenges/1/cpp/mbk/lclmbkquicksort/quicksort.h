#ifndef INC_LCL_MBK_ALGORITHMS_QUICKSORT_H
#define INC_LCL_MBK_ALGORITHMS_QUICKSORT_H

#include <queue>
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

			struct Boundary
			{
				Boundary(size_t s, size_t e) : start(s), end(e) {}

				size_t start;
				size_t end;
			};

			template<typename T>
			void quickSort_nonRecursive(std::vector<T>& data, std::queue<Boundary>& boundaries)
			{
				while (!boundaries.empty())
				{
					Boundary boundary = boundaries.front();
					boundaries.pop();

					if (boundary.start >= boundary.end)
						continue;

					size_t pivot = boundary.start;

					for (size_t i = boundary.start + 1; i <= boundary.end; ++i)
					{
						if (data[i] < data[pivot])
						{
							if (pivot + 1 != i)
								swap(data, pivot, pivot + 1);
							swap(data, pivot, i);
							pivot += 1;
						}
					}

					if (pivot > boundary.start)
						boundaries.push(Boundary(boundary.start, pivot - 1));
					if (pivot < boundary.end)
						boundaries.push(Boundary(pivot + 1, boundary.end));
				}
			}

			template<typename T>
			void quickSort_nonRecursive(std::vector<T>& data)
			{
				std::queue<Boundary> boundaries;
				boundaries.push(Boundary(0, data.size() - 1));
				quickSort_nonRecursive(data, boundaries);
			}

			template<typename T>
			void quickSort_tailRecursive(std::vector<T>& data, std::queue<Boundary>& boundaries)
			{
				if (boundaries.empty())
					return;

				Boundary boundary = boundaries.front();
				boundaries.pop();

				if (boundary.start < boundary.end)
				{
					size_t pivot = boundary.start;

					for (size_t i = boundary.start + 1; i <= boundary.end; ++i)
					{
						if (data[i] < data[pivot])
						{
							if (pivot + 1 != i)
								swap(data, pivot, pivot + 1);
							swap(data, pivot, i);
							pivot += 1;
						}
					}

					if (pivot > boundary.start)
						boundaries.push(Boundary(boundary.start, pivot - 1));
					if (pivot < boundary.end)
						boundaries.push(Boundary(pivot + 1, boundary.end));
				}

				quickSort_tailRecursive(data, boundaries);
			}

			template<typename T>
			void quickSort_tailRecursive(std::vector<T>& data)
			{
				std::queue<Boundary> boundaries;
				boundaries.push(Boundary(0, data.size() - 1));
				quickSort_tailRecursive(data, boundaries);
			}
		}
	}
}

#endif

