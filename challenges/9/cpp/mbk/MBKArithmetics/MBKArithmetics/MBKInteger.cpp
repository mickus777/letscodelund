#include "MBKInteger.h"

#include <sstream>

namespace mbk
{
	namespace arithmetics
	{
		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger::MBKInteger()
			: _value(8, false)
		{
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger::MBKInteger(int value)
			: _value(8, false)
		{
			for (size_t i = 0; i < 8; ++i)
			{
				_value[i] = value & 0x1;
				value = value >> 1;
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger::MBKInteger(const MBKInteger& other)
			: _value(other._value)
		{
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger::operator int() const
		{
			int value = 0;

			int multiplier = 1;
			for (size_t i = 0; i < 8; ++i)
			{
				value += multiplier * (_value[i] ? 1 : 0);
				multiplier *= 2;
			}

			return value;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		std::wstring MBKInteger::toWString() const
		{
			std::wstringstream stream;

			stream << operator int();

			return stream.str();
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		bool MBKInteger::operator==(const MBKInteger& other) const
		{
			for (size_t i = 0; i < 8; ++i)
				if (_value[i] != other._value[i])
					return false;

			return true;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		bool MBKInteger::operator<(const MBKInteger& other) const
		{
			for (size_t i = 8; i > 0; --i)
			{
				if (_value[i - 1] && !other._value[i - 1])
					return false;
				if (!_value[i - 1] && other._value[i - 1])
					return true;
			}

			return false;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		bool MBKInteger::operator>(const MBKInteger& other) const
		{
			for (size_t i = 8; i > 0; --i)
			{
				if (_value[i - 1] && !other._value[i - 1])
					return true;
				if (!_value[i - 1] && other._value[i - 1])
					return false;
			}

			return false;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger& MBKInteger::operator=(const MBKInteger& other)
		{
			_value = other._value;

			return *this;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger MBKInteger::operator+(const MBKInteger& other) const
		{
			MBKInteger result(0);

			bool remainder = false;
			for (size_t i = 0; i < 8; ++i)
			{
				int selector = (_value[i] ? 1 : 0) + 2 * (other._value[i] ? 1 : 0) + 4 * (remainder ? 1 : 0);

				switch (selector)
				{
				case 0:
					break;
				case 1:
				case 2:
				case 4:
					remainder = false;
					result._value[i] = true;
					break;
				case 3:
				case 5:
				case 6:
					remainder = true;
					result._value[i] = false;
					break;
				case 7:
					remainder = true;
					result._value[i] = true;
					break;
				}
			}

			return result;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger MBKInteger::operator-(const MBKInteger& other) const
		{
			MBKInteger result(0);

			bool borrowed = false;
			for (size_t i = 0; i < 8; ++i)
			{
				int selector = (_value[i] ? 1 : 0) + 2 * (other._value[i] ? 1 : 0) + 4 * (borrowed ? 1 : 0);

				switch (selector)
				{
				case 0:
					break;
				case 1:
					borrowed = false;
					result._value[i] = true;
					break;
				case 2:
				case 4:
				case 7:
					borrowed = true;
					result._value[i] = true;
					break;
				case 3:
				case 5:
					borrowed = false;
					result._value[i] = false;
					break;
				case 6:
					borrowed = true;
					result._value[i] = false;
					break;
				}
			}

			return result;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger MBKInteger::operator*(const MBKInteger& other) const
		{
			MBKInteger factor1(*this);
			MBKInteger factor2(other);
			MBKInteger product;

			for (size_t i = 0; i < 8; ++i)
			{
				if (factor1._value[i])
					product = product + factor2;
				factor2 <<= MBKInteger(1);
			}

			return product;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger MBKInteger::operator/(const MBKInteger& other) const
		{
			MBKInteger remainder(*this);
			MBKInteger one(1);
			MBKInteger value(1);

			while (remainder > other)
			{
				value = value + one;
				remainder = remainder - other;
			}

			return value;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger& MBKInteger::operator<<=(MBKInteger steps)
		{
			MBKInteger zero;
			MBKInteger one(1);

			while (!(zero == steps))
			{
				bool last = false;
				for (size_t i = 0; i < 8; ++i)
				{
					bool bit = _value[i];
					_value[i] = last;
					last = bit;
				}

				steps = steps - one;
			}

			return *this;
		}

		///////////////////////////////////////////////////////////////////////////////////////////
		MBKInteger& MBKInteger::operator>>=(MBKInteger steps)
		{
			MBKInteger zero;
			MBKInteger one(1);

			while (!(zero == steps))
			{
				for (size_t i = 0; i < 8; ++i)
				{
					if (i < 7)
						_value[i] = _value[i + 1];
					else
						_value[i] = false;
				}

				steps = steps - one;
			}

			return *this;
		}
	}
}