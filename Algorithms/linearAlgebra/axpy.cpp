#include <iostream>
#include <vector>


// Finds the vector that is the result of vector X scaled by Alpha added to vector Y
int main()
{
	int set_vector_size;
	std::vector<int> x, y;

	std::cout << "Size of vector x and y: " << std::endl;
	std::cin  >> set_vector_size;
	x.resize(set_vector_size);
	y.resize(set_vector_size);

	int alpha;
	std::cout << "What is the value of scaler alpha: " << std::endl;
	std::cin  >> alpha;

	// Get components for X and Y
	std::cout << "Enter the " << set_vector_size << " component/s of the vector x: " << std::endl;
	for (int index = 0; index < x.size(); index++)
    	{
        	std::cin >> x[index];
    	}

	std::cout << "Enter the " << set_vector_size << " component/s of the vector y: " << std::endl;
	for (int index = 0; index < y.size(); index++)
	{
        	std::cin >> y[index];
   	}

	// Perform the AXPY algorithm
	for (int index = 0; index < x.size(); index++)
	{
		y[index] += (alpha * x[index]);
	}

	// Print the result
	for (int component : y)
    	{
        	std::cout << component << std::endl;
    	}

	system("pause");
	return 0;
}
