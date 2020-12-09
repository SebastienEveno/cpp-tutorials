#include "Point3d.hpp"
#include "Vector3d.hpp"

#include <iostream>

void Point3d::moveByVector(const Vector3d &v)
{
    m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

void Point3d::print() const
{
    std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

