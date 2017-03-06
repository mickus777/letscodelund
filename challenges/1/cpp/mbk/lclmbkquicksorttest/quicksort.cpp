#include "stdafx.h"
#include "CppUnitTest.h"

#include "lclmbkquicksort\quicksort.h"

#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			template <>
			static std::wstring ToString(const std::vector<int>& q)
			{
				std::wstringstream stream;

				stream << "[";
				for (size_t i = 0; i < q.size(); ++i)
				{
					if (i > 0)
						stream << L", ";
					stream << q[i];
				}
				stream << "]";

				return stream.str();
			}
		}
	}
}

namespace lclmbkquicksorttest
{		
	TEST_CLASS(TestQuickSort)
	{
	public:
		
		TEST_METHOD(QuickSort_QuickSort)
		{
			std::vector<int> data(7);
			data[0] = 3;
			data[1] = 5;
			data[2] = 7;
			data[3] = 2;
			data[4] = 1;
			data[5] = 6;
			data[6] = 4;

			lcl::mbk::algorithms::quickSort(data);

			std::vector<int> expected(7);
			for (int i = 1; i < 8; ++i)
				expected[i - 1] = i;

			Assert::AreEqual(expected, data);
		}

		TEST_METHOD(QuickSort_NonRecursive)
		{
			std::vector<int> data(7);
			data[0] = 3;
			data[1] = 5;
			data[2] = 7;
			data[3] = 2;
			data[4] = 1;
			data[5] = 6;
			data[6] = 4;

			lcl::mbk::algorithms::quickSort_nonRecursive(data);

			std::vector<int> expected(7);
			for (int i = 1; i < 8; ++i)
				expected[i - 1] = i;

			Assert::AreEqual(expected, data);
		}

		TEST_METHOD(QuickSort_TailRecursive)
		{
			std::vector<int> data(7);
			data[0] = 3;
			data[1] = 5;
			data[2] = 7;
			data[3] = 2;
			data[4] = 1;
			data[5] = 6;
			data[6] = 4;

			lcl::mbk::algorithms::quickSort_tailRecursive(data);

			std::vector<int> expected(7);
			for (int i = 1; i < 8; ++i)
				expected[i - 1] = i;

			Assert::AreEqual(expected, data);
		}
	};
}