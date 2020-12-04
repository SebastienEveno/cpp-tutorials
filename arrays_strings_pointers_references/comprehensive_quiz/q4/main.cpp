/*
https://www.learncpp.com/cpp-tutorial/6-x-chapter-6-comprehensive-quiz/

Question #4

Write a function to print a C-style string character by character. 
Use a pointer to step through each character of the string and 
print that character. Stop when you hit the null terminator. 
Write a main function that tests the function with the string 
literal “Hello, world!”.
*/
#include <iostream>

void printCharacterByCharacter(const char* str)
{
    while (*str != '\0')
    {
        std::cout << *str << '\n';
        ++str;
    }
}

int main()
{
    printCharacterByCharacter("Hello, world!");
    return 0;
}
