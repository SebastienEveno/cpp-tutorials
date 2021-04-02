#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "point.hpp"

class Shape
{
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& p)
    {
        return p.print(out);
    }

    virtual ~Shape() = default;
};

class Triangle : public Shape
{
private:
    Point m_x;
    Point m_y;
    Point m_z;
public:
    Triangle(const Point& x, const Point& y, const Point& z) : m_x{x}, m_y{y}, m_z{z} {}

    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_x << ", " << m_y << ", " << m_z <<")\n";
        return out;
    }   
};

class Circle : public Shape
{
private:
    Point m_center;
    int m_radius;
public:
    Circle(const Point& center, int radius) : m_center{ center }, m_radius{ radius } {}
    
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", radius " << m_radius <<")\n";
        return out;
    }

    int getRadius() const { return m_radius; }
};

int getLargestRadius(const std::vector<Shape*> &v)
{
    int largestRadius{ 0 };
    for(const auto* element : v)
    {
        if(auto *c{ dynamic_cast<const Circle*>(element) })
        {
            if(c->getRadius() > largestRadius)
                largestRadius = c->getRadius();
        }
    }
    return largestRadius;
}

#endif