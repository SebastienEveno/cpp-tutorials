#ifndef AVERAGE_HPP
#define AVERAGE_HPP

#include <iostream>
#include <cstdint> // for fixed width integers

class Average
{
private:
    std::int_least32_t m_sum{ 0 };
    std::int_least8_t m_numbers_seen{ 0 };
public:
    Average() {}

    friend std::ostream& operator<<(std::ostream &out, const Average &average)
    {
        out << static_cast<double>(average.m_sum) / average.m_numbers_seen;
        return out;
    }

    Average& operator+=(int n)
    {
        m_sum += n;
        ++m_numbers_seen;
        return *this;
    }
};

#endif