// https://www.learncpp.com/cpp-tutorial/813-friend-functions-and-classes/

#include "Vector3d.hpp"
#include "Point3d.hpp"

int main()
{
	Point3d p{1.0, 2.0, 3.0};
	Vector3d v{2.0, 2.0, -3.0};
 
	p.print();
	p.moveByVector(v);
	p.print();
 
	return 0;
}