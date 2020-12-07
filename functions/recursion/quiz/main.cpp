// https://www.learncpp.com/cpp-tutorial/7-11-recursion/

#include <iostream>

int factorial(const int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int sumDigits(const int n)
{
    if (n < 10)
        return n;
    else
        return (n % 10) + sumDigits(n / 10);
}

int main()
{
    for (int i{1}; i < 8; ++i)
    {
        std::cout << factorial(i) << '\n';
    }
    int s{ sumDigits(350) };
    std::cout << s;
    return 0;
}