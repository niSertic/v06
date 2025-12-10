#pragma once
#include <iostream>


namespace vsite::oop::v7 {

	class money {
		long long cents;

	public:
		money(long long eur = 0, int ct = 0);

		money& operator+=(const money& other);
		money& operator-=(const money& other);

		friend std::ostream& operator<<(std::ostream& os, const money& m);
		friend std::istream& operator>>(std::istream& is, money& m);

	};
}
