#include "stdafx.h"

#include "CppUnitTest.h"

#include "MBKInteger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template <>
			static std::wstring ToString(const mbk::arithmetics::MBKInteger& v)
			{
				return v.toWString();
			}
		}
	}
}

namespace MBKArithmeticsTest
{		
	TEST_CLASS(MBKIntegerTest)
	{
	public:
		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_Create)
		{
			mbk::arithmetics::MBKInteger value(7);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_CastToInt)
		{
			int result = 5;
			
			mbk::arithmetics::MBKInteger value(result);

			Assert::AreEqual(result, static_cast<int>(value));
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_ToWString)
		{
			mbk::arithmetics::MBKInteger value(13);

			Assert::AreEqual(std::wstring(_T("13")), value.toWString());
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_Equality)
		{
			mbk::arithmetics::MBKInteger value1(5);
			mbk::arithmetics::MBKInteger value2(5);

			Assert::AreEqual(true, value1 == value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_Equality_NotEqual)
		{
			mbk::arithmetics::MBKInteger value1(5);
			mbk::arithmetics::MBKInteger value2(6);

			Assert::AreEqual(false, value1 == value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_LessThan)
		{
			mbk::arithmetics::MBKInteger value1(13);
			mbk::arithmetics::MBKInteger value2(17);

			Assert::AreEqual(true, value1 < value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_LessThan_Equal)
		{
			mbk::arithmetics::MBKInteger value1(15);
			mbk::arithmetics::MBKInteger value2(15);

			Assert::AreEqual(false, value1 < value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_LessThan_False)
		{
			mbk::arithmetics::MBKInteger value1(61);
			mbk::arithmetics::MBKInteger value2(42);

			Assert::AreEqual(false, value1 < value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_Assignment)
		{
			mbk::arithmetics::MBKInteger value1(3);
			mbk::arithmetics::MBKInteger value2(49);

			mbk::arithmetics::MBKInteger result(value2);

			Assert::AreEqual(result, value1 = value2);
			Assert::AreEqual(result, value1);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_Addition)
		{
			mbk::arithmetics::MBKInteger value1(5);
			mbk::arithmetics::MBKInteger value2(6);

			mbk::arithmetics::MBKInteger result(11);

			Assert::AreEqual(result, value1 + value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_Subtraction)
		{
			mbk::arithmetics::MBKInteger value1(34);
			mbk::arithmetics::MBKInteger value2(9);

			mbk::arithmetics::MBKInteger result(25);

			Assert::AreEqual(result, value1 - value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_Multiplication)
		{
			mbk::arithmetics::MBKInteger value1(5);
			mbk::arithmetics::MBKInteger value2(6);

			mbk::arithmetics::MBKInteger result(30);

			Assert::AreEqual(result, value1 * value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_Division)
		{
			mbk::arithmetics::MBKInteger value1(42);
			mbk::arithmetics::MBKInteger value2(7);

			mbk::arithmetics::MBKInteger result(6);

			Assert::AreEqual(result, value1 / value2);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_ShiftLeftInPlace)
		{
			mbk::arithmetics::MBKInteger value(18);
			mbk::arithmetics::MBKInteger steps(3);

			mbk::arithmetics::MBKInteger result(144);

			Assert::AreEqual(result, value <<= steps);
			Assert::AreEqual(result, value);
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(MBKInteger_ShiftRightInPlace)
		{
			mbk::arithmetics::MBKInteger value(147);
			mbk::arithmetics::MBKInteger steps(3);

			mbk::arithmetics::MBKInteger result(18);

			Assert::AreEqual(result, value >>= steps);
			Assert::AreEqual(result, value);
		}
	};
}
