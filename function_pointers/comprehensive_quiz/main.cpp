#include <iostream>
#include <functional> // for std::function

int getInteger()
{
    std::cout << "Enter an integer:" << '\n';
    int a{};
    std::cin >> a;
    return a;
}

char getOperation()
{
    char ch{};
    do
    {
        std::cout << "Enter a mathematical operation ('+', '-', '*', '/'):" << '\n';
        std::cin >> ch;
    } while (ch != '+' && ch != '-' && ch != '*' && ch != '/');
    return ch;
}

int add(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
    switch(op)
    {
        default:
        case '+':
            return add;
        case '-':
            return substract;
        case '*':
            return multiply;
        case '/':
            return divide;
    }
}

int main()
{
    int a{ getInteger() };
    int b{ getInteger() };
    char op{ getOperation() };

    std::cout << a << ' ' << op << ' ' << b << " = " << getArithmeticFunction(op)(a, b);

    return 0;
}