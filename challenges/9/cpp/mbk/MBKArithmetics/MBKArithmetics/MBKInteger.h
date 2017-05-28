#ifndef INC_MBK_ARITHMETICS_INTEGER_H
#define INC_MBK_ARITHMETICS_INTEGER_H

#include <vector>

namespace mbk
{
	namespace arithmetics
	{
		class MBKInteger
		{
		public:
			MBKInteger();
			MBKInteger(int v);
			MBKInteger(const MBKInteger& other);

			explicit operator int() const;

			bool operator==(const MBKInteger& other) const;
			bool operator<(const MBKInteger& other) const;
			bool operator>(const MBKInteger& other) const;

			MBKInteger& operator=(const MBKInteger& other);
			MBKInteger operator+(const MBKInteger& other) const;
			MBKInteger operator-(const MBKInteger& other) const;
			MBKInteger operator*(const MBKInteger& other) const;
			MBKInteger operator/(const MBKInteger& other) const;

			MBKInteger& operator<<=(MBKInteger steps);
			MBKInteger& operator>>=(MBKInteger steps);

			std::wstring toWString() const;

		private:
			std::vector<bool> _value;
		};
	}
}

#endif
