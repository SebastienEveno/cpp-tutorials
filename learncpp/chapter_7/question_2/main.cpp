#include <iostream>
#include <cassert>
 
bool isPrime(int x)
{
    // write this function using a for loop
    int number_of_divisors{ 1 }; // number of divisors of x
    for(int test{ 2 }; test <= x; ++test)
    {
        if (x % test == 0)
            ++number_of_divisors;
    }
    return number_of_divisors == 2;
}
 
int main()
{
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(!isPrime(99));
    assert(isPrime(13417));
 
    std::cout << "Success!";
 
    return 0;
}