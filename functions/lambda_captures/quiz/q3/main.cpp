// https://www.learncpp.com/cpp-tutorial/lambda-captures/

#include <iostream>
#include <random>
#include <cmath> // for std::abs
#include <algorithm> // std::find, std::min_element
#include <ctime>
#include <vector>

constexpr int min_random{ 2 };
constexpr int max_random{ 4 };

int getRandomInt(int min, int max)
{
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
 
  return std::uniform_int_distribution{ min, max }(mt);
}

int findClosestNumber(const std::vector<int>& numbers, int guess) {
    
    return *std::min_element(numbers.begin(), numbers.end(), [=](int a, int b) -> bool
    {
        return (std::abs(a - guess) < std::abs(b - guess));
    });
}

int main()
{
    std::cout << "Start where?" << '\n';
    int a{};
    std::cin >> a;

    std::cout << "How many?" << '\n';
    int b{};
    std::cin >> b;

    // generate random number
    int random{ getRandomInt(min_random, max_random) };
    
    // create vector
    std::vector<int> numbers{};
    for (int i{ 0 }; i < numbers.size(); ++i)
    {
        numbers.push_back(random * (a + i) * (a + i));
    }
    std::cout << "I generated " << b << " square numbers. Do you know what each number is after multiplying it by " << random << " ?" << '\n';
    
    // start game
    int guess{};
    int numbersLeft{ b };
    bool correct{ true };
    do
    {
        std::cin >> guess;
        auto found { std::find(numbers.begin(), numbers.end(), guess) };
        --numbersLeft;
        if (found == numbers.end())
        {
            correct = false;
            std::cout << guess << " is wrong! Try " << findClosestNumber(numbers, guess) <<" next time." << '\n';
        }
        else
        {
            std::cout << "Nice! " << numbersLeft << " numbers(s) left." << '\n';
            numbers.erase(found);
        }
    } while (numbersLeft > 0 && correct);
    
    return 0;
}