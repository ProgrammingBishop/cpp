#include <iostream>
#include <math.h>

int main()
{
    long long number_to_factor = 0;
    bool is_long_long = false;
    
    while (!is_long_long)
    {
        is_long_long = true;
        std::cout << "Enter a number greater than 0 to factor: " << std::endl;
        std::cin >> number_to_factor;
        
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a valid integer input: " << std::endl;
            std::cin >> number_to_factor;
            is_long_long = false;
        }
    }
    
    if (number_to_factor <= -1)
    {
        std::cout << number_to_factor << std::endl;
        exit(0);
    }
    
    else if (number_to_factor > static_cast<long long>(pow(2.0, 53.0)))
    {
        std::cout << "That number is too large for this application..." <<std::endl;
        exit(0);
    }
    
    while ((number_to_factor % 2) == 0)
    {
        std::cout << 2 << std::endl;
        number_to_factor /= 2;
    }
    
    for (long long factor = 3; 3 < floor(sqrt(number_to_factor)); factor += 2)
    {
        while ((number_to_factor % factor) == 0)
        {
            std::cout << factor << std::endl;
            number_to_factor /= factor;
        }
    }
    
    if (number_to_factor > 2)
    {
        std::cout << number_to_factor << std::endl;
    }
}
