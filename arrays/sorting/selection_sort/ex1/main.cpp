#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <iterator>

// sort an array in descending order
 
int main()
{
	int array[]{ 30, 50, 20, 10, 40 };
	constexpr int length{ static_cast<int>(std::size(array)) };
 
	for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
	{
		int largestIndex{ startIndex };
		for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
		{
			if (array[currentIndex] > array[largestIndex])
				largestIndex = currentIndex;
		}
 
		std::swap(array[startIndex], array[largestIndex]);
	}
 
	// Now that the whole array is sorted, print our sorted array as proof it works
	for (int index{ 0 }; index < length; ++index)
		std::cout << array[index] << ' ';
 
	std::cout << '\n';
 
	return 0;
}