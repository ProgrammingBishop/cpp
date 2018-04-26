#include <iostream>
#include <vector>

int main()
{
	std::cout << "Enter the size for the matrix: " << std::endl;
	int size;
	std::cin >> size;

	std::vector< std::vector<int> > matrix;

	matrix.resize(size);
	for (auto &rows : matrix)
	{
		rows.resize(size);
	}

	// Lower Triangle
	for (int outer = 0; outer < size; outer++)
	{
		for (int inner = 0; inner < size; inner++)
		{
			if (inner <= outer)
			{
				matrix[outer][inner] = inner + 1;
			}

			else
			{
				matrix[outer][inner] = 0;
			}

			std::cout << matrix[outer][inner] << " ";
		}

		std::cout << "\n";
	}

	std::cout << "==============================" << std::endl;

	// Upper Triangle
	for (int outer = 0; outer < size; outer++)
	{
		for (int inner = 0; inner < size; inner++)
		{
			if (inner >= outer)
			{
				matrix[outer][inner] = inner + 1;
			}
			
			else
			{
				matrix[outer][inner] = 0;
			}

			std::cout << matrix[outer][inner] << " ";
		}

		std::cout << "\n";
	}

	std::cout << "==============================" << std::endl;

	// Strictly Upper Triangle
	for (int outer = 0; outer < size; outer++)
	{
		for (int inner = 0; inner < size; inner++)
		{
			if (inner > outer)
			{
				matrix[outer][inner] = inner;
			}

			else
			{
				matrix[outer][inner] = 0;
			}

			std::cout << matrix[outer][inner] << " ";
		}

		std::cout << "\n";
	}

	std::cout << "==============================" << std::endl;

	// Strictly Lower Triangle
	for (int outer = 0; outer < size; outer++)
	{
		for (int inner = 0; inner < size; inner++)
		{
			if (inner < outer)
			{
				matrix[outer][inner] = inner + 1;
			}

			else
			{
				matrix[outer][inner] = 0;
			}

			std::cout << matrix[outer][inner] << " ";
		}

		std::cout << "\n";
	}
	
	system("pause");
	return 0;
}