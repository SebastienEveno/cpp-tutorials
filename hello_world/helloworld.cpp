#include <iostream>
 
int main()
{
	std::cout << "Enter an integer:" << "\n";
	int x {};
	std::cin >> x;
	if (x == 0)
	{
		std::cout << "The value is equal to zero" << '\n';
	}
    
	return 0;
}