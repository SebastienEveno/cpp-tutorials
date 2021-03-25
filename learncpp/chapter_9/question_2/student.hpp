#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student
{
private:
    std::string m_first_name;
    int m_grade;
public:
    void set_name(std::string name) { m_first_name = name; }
    void set_grade(int grade) { m_grade = grade; }
    std::string get_name() const { return m_first_name; }
    int get_grade() const { return m_grade; }
};

#endif