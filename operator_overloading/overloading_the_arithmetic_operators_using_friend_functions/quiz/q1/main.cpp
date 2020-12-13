// https://www.learncpp.com/cpp-tutorial/92-overloading-the-arithmetic-operators-using-friend-functions/

// Question #1

#include <iostream>

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

int main()
{
    Fraction f1{2, 5};
    f1.print();
 
    Fraction f2{3, 8};
    f2.print();
 
    Fraction f3{ f1 * f2 };
    f3.print();
 
    Fraction f4{ f1 * 2 };
    f4.print();
 
    Fraction f5{ 2 * f2 };
    f5.print();
 
    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();
 
    return 0;
}