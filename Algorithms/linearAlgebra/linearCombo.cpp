#include <iostream>
#include <vector>


int main()
{
	int set_vector_size;
	std::vector<int> x, scalers;

	std::cout << "Size of vector x and the scaler vector: " << std::endl;
	std::cin  >> set_vector_size;
	x.resize(set_vector_size);
	scalers.resize(set_vector_size);

	// Get components for X and the Scalers
	std::cout << "Enter the " << set_vector_size << " component/s of the vector x: " << std::endl;
	for (int index = 0; index < x.size(); index++)
    	{
        	std::cin >> x[index];
    	}

	std::cout << "Enter the " << set_vector_size << " component/s of the scaler vector: " << std::endl;
	for (int index = 0; index < scalers.size(); index++)
    	{
        	std::cin >> scalers[index];
    	}

	// Perform the linear combination algorithm
	int linear_combo = 0; 

	for (int index = 0; index < x.size(); index++)
	{
		linear_combo += (x[index] * scalers[index]);
	}

	// Print the result
	std::cout << linear_combo << std::endl;

	system("pause");
	return 0;
}
