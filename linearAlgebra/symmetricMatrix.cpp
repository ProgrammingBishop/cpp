#include <iostream>
#include <vector>

int main()
{
	std::cout << "Enter the size for the matrix: " << std::endl;
	int size;
	std::cin >> size;

	std::vector< std::vector<int> > matrix;

	// Create the dimensions for the matrix
	matrix.resize(size);
	for (auto &rows : matrix)
	{
		rows.resize(size);
	}

	// Set the components for the matrix
	for (int outer = 0; outer < size; outer++)
	{
		std::cout << "Enter the " << size << " values for row " << (outer + 1) << " of the matrix: " << std::endl;

		for (int inner = 0; inner < size; inner++)
		{
			std::cin >> matrix[outer][inner];
		}
	}

	std::cout << "==============================" << std::endl;

	// Check if matrix is symmetiric
	for (int outer = 0; outer < size; outer++)
	{
		for (int inner = 0; inner < size; inner++)
		{
			if (inner == outer || matrix[outer][inner] == matrix[inner][outer])
			{
				continue;
			}

			else
			{
				std::cout << "\nComponents not symmetric at [Row " << 
					outer + 1 << " , Col " << inner + 1 << "] and [Row " << 
					inner + 1 << " , Col " << outer + 1 << "]\n" << 
				std::endl;

				system("pause");
				return 0;
			}
		}
	}

	std::cout << "\nTrue\n" << std::endl;

	system("pause");
	return 0;
}