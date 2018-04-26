#include <iostream>
#include <vector>
#include <math.h>


int main()
{
	int set_vector_size;
	std::vector<int> x;

	std::cout << "Size of vector x: " << std::endl;
	std::cin  >> set_vector_size;
	x.resize(set_vector_size);

	// Get components for X
	std::cout << "Enter the " << set_vector_size << " component/s of the vector x: " << std::endl;
	for (int index = 0; index < x.size(); index++)
    	{
        	std::cin >> x[index];
    	}
	 
	// Get overflow protection alpha
	/*
		While the length of vector x may be in bounds
		The intermediate operations that square each component of X may cause overflow
		By dividing each of the components of X with overflow protection alpha before exponentiation,
		we can assure each component will be less than or equal to 1
	*/
	int currentMax = 0;
	for (int index = 0; index < x.size(); index++)
    	{
		if (x[index] > currentMax)
        	{
            		currentMax = x[index];
        	}
	}

	double alpha = currentMax;

	// Calculate Dot Product
	double summation = 0;
	// Scaler will be the decimal placeholder for each component in X
	double scaler;

	for (int index = 0; index < x.size(); index++)
    	{
		scaler     = (static_cast<double>(x[index]) / alpha);
		summation += (scaler * scaler);
	}

	// Calculate Length
	/*
		Now we multiply the sqrt summation of X's components with 
		alpha to find the final length of the vector X
	*/
	double length = alpha * sqrt(summation);

	// Print the Result
	std::cout << length << std::endl;

	system("pause");
	return 0;
}
