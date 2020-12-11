// https://www.learncpp.com/cpp-tutorial/99-overloading-the-parenthesis-operator/

// Question #1

#include <iostream>
#include <string>

class Mystring
{
    std::string m_name{};
public:
    Mystring(const std::string& name="") : m_name{name}
    {
    }

    std::string operator()(int start, int length);
};

std::string Mystring::operator()(int start, int length)
{
    std::string res{ m_name[start] };
    for(int k {start + 1}; k < start + length; ++k)
        res += m_name[k];
    return res;
}

int main()
{
    Mystring string{ "Hello, world!" };
    std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters
 
    return 0;
}