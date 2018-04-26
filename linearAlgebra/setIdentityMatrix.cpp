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

	for (int outer = 0; outer < size; outer++)
	{
		for (int inner = 0; inner < size; inner++)
		{
			/*
			Uncomment next line of code and
			comment if else block for a zero matrix
			*/

			//matrix[outer][inner] = 0;

			if (outer == inner) {
				matrix[outer][inner] = 1;
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