#include <iostream>
#include <cassert>

class IntArray
{
private:
    int m_length{};
    int *m_array{ nullptr };
public:
    IntArray(int length) : m_length{length}
    {
        assert(length > 0 && "IntArray length should be positive integer");
        m_array = new int[m_length]{};
    }

    // Copy constructor that does a deep copy
	IntArray(const IntArray &array): m_length{ array.m_length }
	{
		// Allocate a new array
		m_array = new int[m_length];
 
		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];
	}

    ~IntArray()
	{
		delete[] m_array;
	}

    friend std::ostream& operator<<(std::ostream &out, const IntArray &array)
	{
		for (int count{ 0 }; count < array.m_length; ++count)
		{
			out << array.m_array[count] << ' ';
		}
		return out;
	}

    int& operator[](const int index)
	{
		assert(index >= 0);
		assert(index < m_length);
		return m_array[index];
    }

    // Assignment operator that does a deep copy
	IntArray& operator=(const IntArray &array)
	{
		// self-assignment guard
		if (this == &array)
			return *this;
 
		// If this array already exists, delete it so we don't leak memory
		delete[] m_array;
 
		m_length = array.m_length;
 
		// Allocate a new array
		m_array = new int[m_length];
 
		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];
 
		return *this;
	}
    
};