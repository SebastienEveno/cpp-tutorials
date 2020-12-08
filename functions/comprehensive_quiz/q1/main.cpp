// https://www.learncpp.com/cpp-tutorial/7-x-chapter-7-comprehensive-quiz/

#include <vector>
// a) A function named max() that takes two doubles and
// returns the larger of the two.

int max(const double a, const double b);

// b) A function named swap() that swaps two integers.
void swap(int& a, int& b);

// c) A function named getLargestElement() that takes a dynamically 
// allocated array of integers and returns the largest number in 
// such a way that the caller can change the value of the 
// element returned (don’t forget the length parameter).

int& getLargestElement(int *array, int lenght);
