/*
https://www.learncpp.com/cpp-tutorial/6-x-chapter-6-comprehensive-quiz/

Question #3

Write your own function to swap the value of two integer 
variables. Write a main() function to test it.
*/

#include <iostream>

void swap(int& a, int& b)
{
    int tmp{a};
    a = b;
    b = tmp;
}

int main() 
{
    std::cout << "Enter an integer (a):" << '\n';
    int a{};
    std::cin >> a;
    std::cout << "Enter another integer (b):" << '\n';
    int b{};
    std::cin >> b;
    swap(a, b);
    std::cout << "a is now " << a << " and b is now " << b << '\n';
    return 0;
}