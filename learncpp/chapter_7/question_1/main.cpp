#include <iostream>
#include "constants.hpp"
 
void calculateAndPrintHeight(double currentHeight, int time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << currentHeight << "\n";
}

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen = myConstants::gravity * seconds * seconds / 2;
    return initialHeight - distanceFallen;
}
 
int main()
{
    using namespace std;
    cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    cin >> initialHeight;
	
    double currentHeight{ initialHeight };
    int seconds { 0 };

    while(currentHeight >= 0.)
    {
        calculateAndPrintHeight(currentHeight, seconds++);
        currentHeight = calculateHeight(initialHeight, seconds);
    }
	
    return 0;
}