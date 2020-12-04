/*
https://www.learncpp.com/cpp-tutorial/6-x-chapter-6-comprehensive-quiz/

Question #2

Write the following program: Create a struct that holds a 
student’s first name and grade (on a scale of 0-100). Ask 
the user how many students they want to enter. Create a 
std::vector to hold all of the students. Then prompt the user 
for each name and grade. Once the user has entered all the names 
and grade pairs, sort the list by grade (highest first). Then 
print all the names and grades in sorted order.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Student
{
    std::string name{};
    int grade{};
};

bool compareStudent(const Student& a, const Student& b)
{
    return (a.grade > b.grade);
}

int getNumberOfStudents()
{
    int numberOfStudents{};
    do
    {
        std::cout << "How many students do you want to enter? " << '\n';
        std::cin >> numberOfStudents;
    } while (numberOfStudents <= 0);
    return numberOfStudents;
}

std::vector<Student> getStudents()
{
    int numberOfStudents{ getNumberOfStudents() };
    std::vector<Student> students(static_cast<std::vector<Student>::size_type>(numberOfStudents));
    int studentNumber{1};
    for (auto& student : students)
    {
        std::cout << "Enter name #" << studentNumber <<": " << '\n';
        std::cin >> student.name;
        std::cout << "Enter grade #" << studentNumber << ": " << '\n';
        std::cin >> student.grade;
        ++studentNumber;
    }
    return students;
}

int main() 
{
    auto students { getStudents() };

    // list by grade (higher first)
    std::sort(students.begin(), students.end(), compareStudent);

    // Print
    for (auto& element : students)
    {
        std::cout << element.name << " got a grade of " << element.grade << '\n';
    }

    return 0;
}