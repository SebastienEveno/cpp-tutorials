#include <iostream>
#include <cmath>

class Point2d
{
private:
    double m_x;
    double m_y;
public:
    Point2d(double x=0., double y=0.) : m_x{x}, m_y{y} {}
    double get_x() const { return m_x; }
    double get_y() const { return m_y; }
    void print() const { std::cout <<"Point2d(" << m_x << ", " << m_y << ")\n"; }
    double distanceTo(const Point2d& p) const
    {
        return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
    }
    friend double distanceFrom(const Point2d& a, const Point2d& b);
};

double distanceFrom(const Point2d& a, const Point2d& b)
{
    return std::sqrt((a.m_x - b.m_x) * (a.m_x - b.m_x) + (a.m_y - b.m_y) * (a.m_x - b.m_y));
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();
    std::cout << "Distance between these two points: " << first.distanceTo(second) << '\n';
    std::cout << "Distance between these two points: " << distanceFrom(first, second) << '\n';
    
    return 0;
}