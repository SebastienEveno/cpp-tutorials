#include <vector>
#include "shape.hpp"

int main()
{
    std::vector<Shape*> v{
      new Circle{Point{1, 2, 3}, 7},
      new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
      new Circle{Point{4, 5, 6}, 3}
    };

	// print each shape in vector v on its own line here
    for (const auto* element : v)
        std::cout << *element << '\n';
    
    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function
 
	// delete each element in the vector here
    for(const auto* element : v)
        delete element;
    
	return 0;
}