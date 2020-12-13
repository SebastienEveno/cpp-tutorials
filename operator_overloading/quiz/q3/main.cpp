// https://www.learncpp.com/cpp-tutorial/9-x-chapter-9-comprehensive-quiz/

// Question #3

#include <iostream>
#include <cstdint>
#include <cmath> // for std::round

class FixedPoint2
{
    std::int_least16_t m_non_frac_part{};
    std::int_least8_t m_frac_part{};
public:
    FixedPoint2(std::int_least16_t non_frac_part=0, std::int_least8_t frac_part=0)
        : m_non_frac_part{non_frac_part}, m_frac_part{frac_part}
    {
        if (m_frac_part > 99)
            m_frac_part = 99;
        if (m_frac_part < -99)
            m_frac_part = -99;
        
        if (m_non_frac_part < 0 || m_frac_part < 0)
        {
            if (m_non_frac_part > 0)
                m_non_frac_part = -m_non_frac_part;
            if (m_frac_part > 0)
                m_frac_part = -m_frac_part;
        }
    }

    FixedPoint2(double d) :
        m_non_frac_part { static_cast<std::int_least16_t>(d) },
        m_frac_part { static_cast<std::int_least8_t>(std::round((d - m_non_frac_part) * 100)) }
    {
    }

    operator double() const
    {
        // return type is double
        return m_non_frac_part + static_cast<double>(m_frac_part) / 100.0;
    }

    friend bool operator==(const FixedPoint2 &f1, const FixedPoint2 &f2)
    {
        return ((f1.m_non_frac_part == f2.m_non_frac_part) && (f1.m_frac_part == f2.m_frac_part));
    }

    friend std::istream& operator>>(std::istream &in, FixedPoint2 &f)
    {
        double input{};
        in >> input;
        f = FixedPoint2{ input };
        return in;
    }

    FixedPoint2 operator-() const
    {
        return { static_cast<std::int_least16_t>(-m_non_frac_part),
                 static_cast<std::int_least8_t>(-m_frac_part)};
    }

    friend FixedPoint2 operator+(const FixedPoint2 &f1, const FixedPoint2 &f2)
    {
        return { static_cast<double>(f1) + static_cast<double>(f2) };
    }
    
    friend std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fp)
    {
        out << static_cast<double>(fp) << '\n';
        return out;
    }

};

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}
 
int main()
{
	testAddition();
 
	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';
 
	std::cout << -a << '\n';
 
	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	
	std::cout << "You entered: " << a << '\n';
 
	return 0;
}