#include <iostream>

void swap(int& a, int& b)
{
    int tmp{ a };
    a = b;
    b = tmp;
}

int main()
{
    int a{2};
    int b{3};
    std::cout << "a = " << a << ", b = " << b << '\n';
    std::cout << "Swapping..." << '\n';
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << '\n';
    return 0;
}