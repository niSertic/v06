#include "money.h"
#include <algorithm>
#include <ostream>
#include <istream>
#include <format>

namespace vsite::oop::v7
{
	money::money(long long eur, int ct) : cents(eur * 100 + ct) {}
    
    money& money::operator+=(const money& other)
    {
        cents += other.cents;
        return *this;
    }
    
    money& money::operator-=(const money& other)
    {
        cents -= other.cents;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const money& m) {
        
        long long value = std::abs(m.cents);

        long long eur = value / 100;
        int ct = value % 100;

        if (m.cents < 0) { 
            os << '-'; 
}

        if (eur == 0 && ct > 0) {
            os << ct << " ct";
        }
        else if (eur > 0 && ct == 0) {
            os << eur << " eur";
        }
        else {
            os << std::format("{} eur, {:02} ct", eur, ct);
        }

        return os;
    }

    std::istream& operator>>(std::istream& is, money& m)
    {
        long long eur;
        int ct;
        if (is >> eur >> ct) {
            m.cents = eur * 100 + ct;
        }
        return is;
    }
}