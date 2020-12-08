// https://www.learncpp.com/cpp-tutorial/83-public-vs-private-access-specifiers/

#include <array>
#include <cassert>
#include <iostream>

class Stack
{
private:
    using array_t = std::array<int, 10>;
    using size_type = array_t::size_type;

    array_t arr;
    size_type m_next{}; // index of the next free element
public:
    void reset()
    {
        m_next = 0;
    }

    bool push(int value)
    {
        if (m_next == arr.size())
        {
            // full
            return false;
        }
        arr[m_next++] = value;
        return true;
    }

    int pop()
    {
        assert(m_next > 0 && "No values on the stack.");
        return arr[--m_next];
    }

    void print()
    {
        std::cout << "( ";
        for (size_type i{ 0 }; i < m_next; ++i)
			std::cout << arr[i] << ' ';
        std::cout << ")\n";
    }

};

int main()
{
	Stack stack;
 
	stack.print();
 
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.reset();
	stack.print();
 
	return 0;
}