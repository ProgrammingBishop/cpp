#include <iostream>
#include <vector>
#include <math.h>


struct MaxSubArray
{
private:
	std::vector <int> sortedArray;

public:
	void buildArrayToSort()
	{
		std::cout << "Enter the number of integers: " << std::endl;
		int input = 0;
		std::cin >> input;

		sortedArray.resize(input);

		std::cout << "Enter the " << input << " numbers: " << std::endl;
		for (int index = 0; index < sortedArray.size(); index++)
		{
			std::cin >> sortedArray[index];
		}
	}

	std::vector<int> getSortedArray() { return sortedArray; }

};


int maxSubArraySum(MaxSubArray &sortedArray, int left, int right);
int maxCrossingSum(MaxSubArray &sortedArray, int left, int middle, int right);
int max(int a, int b, int c);
int max(int a, int b);


int main()
{
	MaxSubArray max_sub_array;
	max_sub_array.buildArrayToSort();
	std::cout << maxSubArraySum(max_sub_array, 0, static_cast<int>(max_sub_array.getSortedArray().size() - 1)) << std::endl;

	system("pause");
	return 0;
}


/*
Recursively solve the sub-arrays while searching for the largest sum between adjacent indexes.
The largest sum could be in the left sub-array, right sub-array, or the middle where the 
sub-arrays cross into each other
*/
int maxSubArraySum(MaxSubArray &sortedArray, int left, int right)
{
	if (left == right)
	{
		return sortedArray.getSortedArray()[left];
	}

	int middle = static_cast<int>(floor((left + right) / 2));

	return max(maxSubArraySum(sortedArray, left, middle),
		       maxSubArraySum(sortedArray, middle + 1, right),
		       maxCrossingSum(sortedArray, left, middle, right));
}


int max(int a, int b, int c) {
	return max(max(a, b), c);
}


int max(int a, int b) {
	return (a > b) ? a : b;
}


/*
Find and return the max sum for both the left and right 
sub-arrays counting away from the middle
*/
int maxCrossingSum(MaxSubArray &sortedArray, int left, int middle, int right)
{
	int sum = 0;
	int left_sum = INT_MIN;

	for (int index = middle; index >= left; index--)
	{
		sum += sortedArray.getSortedArray()[index];

		if (sum > left_sum)
		{
			left_sum = sum;
		}
	}

	sum = 0;
	int right_sum = INT_MIN;

	for (int index = middle + 1; index <= right; index++)
	{
		sum += sortedArray.getSortedArray()[index];

		if (sum > right_sum)
		{
			right_sum = sum;
		}
	}

	return left_sum + right_sum;
}