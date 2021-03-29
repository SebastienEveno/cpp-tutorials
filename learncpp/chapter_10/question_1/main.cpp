#include <iostream>
#include <vector>

double max_double(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

void swap(int& a, int& b)
{
    int tmp { a };
    a = b;
    b = tmp;
}

int& getLargestElement(int* arr, int length);

int main()
{
    // double a{ max_double(1., 2.) };
    int c{ 5 };
    int d{ 6 };
    swap(c, d);
    std::cout << "c, d = " << c << ", " << d;
    return 0;
}