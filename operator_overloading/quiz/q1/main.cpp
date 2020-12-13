// https://www.learncpp.com/cpp-tutorial/9-x-chapter-9-comprehensive-quiz/

#include <iostream>
#include <cstdint>

class Average
{
    std::int_least32_t m_sumSoFar{};
    std::int_least8_t m_numbersSeenSoFar{};
public:
    Average(std::int_least32_t sum=0, std::int_least8_t n=0)
        : m_sumSoFar{sum}, m_numbersSeenSoFar{n}
    {
    }

    friend std::ostream& operator<<(std::ostream &out, const Average &avg);
    
    Average& operator+=(int n)
    {
        m_sumSoFar += n;
        ++m_numbersSeenSoFar;
        return *this;
    }
};

std::ostream& operator<<(std::ostream &out, const Average &avg)
{
    out << static_cast<double>(avg.m_sumSoFar) / avg.m_numbersSeenSoFar << '\n';
    return out;
}

int main()
{
	Average avg{};
	
	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4
	
	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6
 
	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12
 
	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5
 
	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7
 
	Average copy{ avg };
	std::cout << copy << '\n';
 
	return 0;
}