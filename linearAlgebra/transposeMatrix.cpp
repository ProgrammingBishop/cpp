#include <iostream>
#include <vector>

int main()
{
	std::cout << "Enter the size of the rows and cols for the matrix: " << std::endl;
	int rows, cols;
	std::cin >> rows >> cols;

	std::vector< std::vector<int> > matrix;
	std::vector< std::vector<int> > transpose;

	// Set the dimensions of the matrix
	matrix.resize(rows);
	for (auto &row : matrix)
	{
		row.resize(cols);
	}

	// Set the dimensions of the transpose
	transpose.resize(cols);
	for (auto &col : transpose)
	{
		col.resize(rows);
	}

	// Get components for the matrix from the user
	for (int outer = 0; outer < rows; outer++)
	{
		std::cout << "Enter the " << cols << " values for row " << (outer + 1) << " of the matrix: " << std::endl;

		for (int inner = 0; inner < cols; inner++)
		{
			std::cin >> matrix[outer][inner];
		}
	}

	std::cout << "==============================" << std::endl;

	// Perform the transpose algorithm
	std::cout << "The transpose of the matrix is: " << std::endl;
	for (int outer = 0; outer < cols; outer++)
	{
		for (int inner = 0; inner < rows; inner++)
		{
			transpose[outer][inner] = matrix[inner][outer];
			std::cout << transpose[outer][inner] << " ";
		}

		std::cout << "\n";
	}

	system("pause");
	return 0;
}