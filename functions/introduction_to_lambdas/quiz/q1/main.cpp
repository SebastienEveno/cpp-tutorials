// https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
#include <string>
#include <array>
#include <iostream>
#include <algorithm>

struct Student
{
    std::string name{};
    int points{};
};

// lambda function
auto isSmaller
{
    [](const Student& a, const Student& b) -> bool
    {
        return a.points < b.points;
    }
};

int main()
{
    const std::array<Student, 8> arr{
        { { "Albert", 3 },
            { "Ben", 5 },
            { "Christine", 2 },
            { "Dan", 8 }, // Dan has the most points (8).
            { "Enchilada", 4 },
            { "Francis", 1 },
            { "Greg", 3 },
            { "Hagrid", 5 } }
    };
    auto best{ std::max_element(arr.begin(), arr.end(), isSmaller) };
    std::cout << best->name << " is the best student.";

    return 0;
}


