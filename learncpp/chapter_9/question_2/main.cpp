#include <iostream>
#include <vector>
#include <algorithm>

#include "student.hpp"

bool sort_students(const Student& student_1, const Student& student_2)
{
    return student_1.get_grade() > student_2.get_grade();
}

int get_number_of_students()
{
    int n{};
    while(true)
    {
        std::cout << "How many students do you wanna enter?\n";
        std::cin >> n;
        if (n >= 0)
            break;
    }
    return n;
}

using vector_type = std::vector<Student>;
int main()
{
    int n{ get_number_of_students() };

    vector_type students(static_cast<vector_type::size_type>(n));
    std::string first_name;
    int grade;
    for(auto& student : students)
    {
        std::cout << "Enter a student name: " << '\n';
        std::cin >> first_name;
        std::cout << "Enter a student grade: " << '\n';
        std::cin >> grade;

        student.set_grade(grade);
        student.set_name(first_name);
    }

    std::sort(students.begin(), students.end(), sort_students);

    for(auto& student : students)
    {
        std::cout << student.get_name() << " got a grade of " << student.get_grade() << '\n';
    }
    return 0;
}