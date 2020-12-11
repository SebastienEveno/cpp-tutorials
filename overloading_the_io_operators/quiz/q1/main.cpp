// https://www.learncpp.com/cpp-tutorial/92-overloading-the-arithmetic-operators-using-friend-functions/

// Question #1

#include <iostream>
#include <limits>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator=0, int denumerator=1) : m_numerator{numerator}, m_denominator{denumerator}
    {
        reduce();
    }

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    static int gcd(int a, int b) 
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }

    void reduce()
    {
        if (m_numerator != 0 && m_denominator != 0)
		{
			int gcd{ Fraction::gcd(m_numerator, m_denominator) };
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);

    friend Fraction operator*(int n, const Fraction &f);

    friend Fraction operator*(const Fraction &f, int n);

    friend std::ostream& operator<<(std::ostream &out, const Fraction &f);

    friend std::istream& operator>>(std::istream &in, Fraction &f);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(int n, const Fraction &f)
{
    return { n * f.m_numerator, f.m_denominator };
}

Fraction operator*(const Fraction &f, int n)
{
    return { n * f.m_numerator, f.m_denominator };
}

std::ostream& operator<<(std::ostream &out, const Fraction& f)
{
    out << f.m_numerator << '/' << f.m_denominator;
    return out;
}

std::istream& operator>>(std::istream &in, Fraction& f)
{
    in >> f.m_numerator;
    
    // Ignore the '/' separator
	in.ignore(std::numeric_limits<std::streamsize>::max(), '/');

    in >> f.m_denominator;

    // Since we overwrite the existing f, we need to reduce again
	f.reduce();

    return in;
}

int main()
{
	Fraction f1{};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;
 
	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;
 
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value
 
	return 0;
}