#include <string>
#include <vector>
/*1) A function named sumTo() that takes an integer parameter 
and returns the sum of all the numbers between 1 and the 
input number.*/

int sumTo(const int value);

/*2) A function named printEmployeeName() that takes an Employee 
struct as input.*/

struct Employee
{
};
void printEmployeeName(const Employee &employee);

/*3) A function named minmax() that takes two integers as input 
and returns back to the caller the smaller and larger number in
a std::pair. A std::pair works identical to a std::tuple but 
stores exactly two elements.*/

std::pair<int, int> minmax(const int a, const int b);

/*4) A function named getIndexOfLargestValue() that takes an integer
array (as a std::vector), and returns the index of the largest 
element in the array.*/

int getIndexOfLargestValue(const std::vector<int>& v);

/*5) A function named getElement() that takes an array of std::string
(as a std::vector) and an index and returns the array element at 
that index (not a copy). Assume the index is valid, and the return
value is const.*/

const std::string& getElement(const std::vector<std::string>& array, const int ind);