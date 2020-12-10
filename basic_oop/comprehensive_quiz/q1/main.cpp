// https://www.learncpp.com/cpp-tutorial/8-15-chapter-8-comprehensive-quiz/

// Question #1

#include <iostream> // for std::cout
#include <cmath> // for std::sqrt

class Point2d
{
    double m_x{};
    double m_y{};
public:
    Point2d(double x=0.0, double y=0.0) : m_x{x}, m_y{y}
    {
    }

    void print()
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n"; 
    }

    // double distanceTo(const Point2d &p) const
    // {
    //     return std::sqrt((m_x - p.m_x)*(m_x - p.m_x) + (m_y - p.m_y)*(m_y - p.m_y));
    // }

    friend double distanceFrom(const Point2d &p1, const Point2d &p2);
};

double distanceFrom(const Point2d &p1, const Point2d &p2)
{
    return std::sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
    return 0;
}