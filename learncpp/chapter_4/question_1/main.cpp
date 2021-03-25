#include <iostream>

double readDouble()
{
    double x{};
    std::cout << "Enter a double value: ";
    std::cin >> x;
    return x;
}

char getOperation()
{
    std::cout << "Enter one of the following:  +, -, *, or /: ";
    char ch {};
    while (true)
    {
        std::cin >> ch;
        if (ch == '+' || ch =='-' || ch == '*' || ch == '/')
            break;
        else
        {
            std::cout << "Enter one of the following:  +, -, *, or /: ";
        }
    }
    return ch;
}

void getResult(char ch, double x, double y)
{
    switch(ch)
    {
        case '+':
            std::cout << x << " + " << y << " is " << x + y;
            break;
        case '-':
            std::cout << x << " - " << y << " is " << x - y;
            break;
        case '*':
            std::cout << x << " * " << y << " is " << x * y;
            break;
        case '/':
            std::cout << x << " / " << y << " is " << x / y;
            break;
    }
}

int main()
{
    double x{ readDouble() };
    double y{ readDouble() };
    char ch{ getOperation() };
    getResult(ch, x, y);

    return 0;
}