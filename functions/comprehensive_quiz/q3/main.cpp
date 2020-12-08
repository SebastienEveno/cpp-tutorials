// https://www.learncpp.com/cpp-tutorial/7-x-chapter-7-comprehensive-quiz/
#include <iostream>
#include <iterator>
 
// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearchIterative(const int *array, int target, int min, int max)
{
    int midpoint{};
    do
    {
        // calculate midpoint
        midpoint = min + (max - min) / 2;
        // compare element with target
        if (array[midpoint] > target)
            max = midpoint - 1;
        else if (array[midpoint] < target)
            min = midpoint + 1;
        else // array[midpoint] = target
            return midpoint;
    } while (min <= max);

    // not found
    return -1;
}

// recursive
int binarySearchRecursive(const int *array, int target, int min, int max)
{
    if (min > max)
    {
        return -1;
    }
    else
    {
        // calculate midpoint
        int midpoint{ min + (max - min) / 2 };
        if (array[midpoint] > target)
            return binarySearchRecursive(array, target, min, midpoint - 1);
        else if (array[midpoint] < target)
            return binarySearchRecursive(array, target, midpoint + 1, max);
        else // array[midpoint] = target
            return midpoint;
    }
}
 
int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
 
    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 9 };
    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };
 
    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{ binarySearchIterative(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
             std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
             std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }
 
    return 0;
}