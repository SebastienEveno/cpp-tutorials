// https://www.learncpp.com/cpp-tutorial/9-x-chapter-9-comprehensive-quiz/

// Question #2

#include <iostream>
#include <cassert>

class IntArray
{
    int m_size{};
    int *m_arr{};
public:
    IntArray(int size=0) : m_size{size}
    {
        assert(size > 0 && "Length must be positive integer.");
        m_arr = new int[m_size]{};
    }

    // Copy constructor
    IntArray(const IntArray &arr) : m_size{arr.m_size}
    {
        // Allocate a new array
        m_arr = new int[m_size]{};

        // Copy elements from the original array to new array
        for (int count{ 0 }; count < arr.m_size; ++count)
            m_arr[count] = arr.m_arr[count];
    }

    ~IntArray()
    {
        delete[] m_arr;
    }

    friend std::ostream& operator<<(std::ostream &out, const IntArray &arr)
    {
        for (int i{ 0 }; i < arr.m_size; ++i)
        {
            out << arr.m_arr[i] << ' ';
        }

        return out;
    }

    int& operator[](const int ind)
    {
        assert(ind >= 0);
        assert(ind < m_size);
        return m_arr[ind];
    }

    IntArray& operator=(const IntArray &arr)
    {
        // Self-assignment guard
        if (this == &arr)
            return *this;
        
        // If this array already exists, delete it so we don't leak memory
        delete[] m_arr;
        m_size = arr.m_size;
        // Allocate new array
        m_arr = new int[m_size]{};
        for (int count{ 0 }; count < m_size; ++count)
            m_arr[count] = arr.m_arr[count];
        
        return *this;
    }

};

IntArray fillArray()
{
	IntArray a(5);
 
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;
 
	return a;
}
 
int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';
 
	auto &ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;
 
	IntArray b(1);
	b = a;
 
	std::cout << b << '\n';
 
	return 0;
}