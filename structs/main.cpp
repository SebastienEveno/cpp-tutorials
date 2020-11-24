#include <iostream>

struct Fraction 
{
    int numerator;
    int denumerator;
};

Fraction getFraction() 
{
    Fraction fraction;
    std::cout << "Enter a numerator" << '\n';
    std::cin >> fraction.numerator;
    std::cout << "Enter a denumerator" << '\n';
    std::cin >> fraction.denumerator;
    if (fraction.denumerator == 0)
        std::cout << "Division by 0 not allowed." << '\n';
    return fraction;
}

double multiply(Fraction fraction_1, 
                Fraction fraction_2) 
{
    return static_cast<double>(fraction_1.numerator * fraction_2.numerator) / (fraction_1.denumerator * fraction_2.denumerator);
}


int main(){
    const Fraction fraction_1{ getFraction() };
    const Fraction fraction_2{ getFraction() };
    std::cout << "The multiplication of the two fractions equals " << multiply(fraction_1, fraction_2) << '\n';
    return 0;
}