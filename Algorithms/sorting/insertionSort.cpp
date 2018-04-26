#include <iostream>
#include <vector>


void buildArrayToSort(std::vector <int> &sortedArray);
void insertionSort(std::vector <int> &sortedArray);
void printSortedArray(std::vector <int> &sortedArray);


int main()
{
	std::vector <int> sortedArray;

	buildArrayToSort(sortedArray);
	insertionSort(sortedArray);
	printSortedArray(sortedArray);
	
	system("pause");
	return 0;
}


void buildArrayToSort(std::vector <int> &sortedArray)
{
	std::cout << "Enter the number of integers to sort: " << std::endl;
	int input = 0;
	std::cin >> input;

	sortedArray.resize(input);

	std::cout << "Enter the " << input << " numbers to be sorted: " << std::endl;
	for (int index = 0; index < sortedArray.size(); index++)
	{
		std::cin >> sortedArray[index];
	}
}


void insertionSort(std::vector <int> &sortedArray)
{
	for (int outer = 1; outer < sortedArray.size(); outer++)
	{
		int key = sortedArray[outer];
		int inner = outer - 1;

		while (inner >= 0 && sortedArray[inner] > key)
		{
			sortedArray[inner + 1] = sortedArray[inner];
			inner -= 1;
		}

		sortedArray[inner + 1] = key;
	}
}


void printSortedArray(std::vector <int> &sortedArray)
{
	for (int index = 0; index < sortedArray.size(); index++)
	{
		std::cout << sortedArray[index] << " ";
	}

	std::cout << "\n" << std::endl;
}