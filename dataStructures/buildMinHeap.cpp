#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


class HeapBuilder {
private:
	std::vector<int> data;
	std::vector< std::pair<int, int> > swaps;

	void WriteResponse() const
	{
		std::cout << swaps.size() << "\n";
		for (int i = 0; i < swaps.size(); ++i)
		{
			std::cout << swaps[i].first << " " << swaps[i].second << "\n";
		}
	}

	void ReadData()
	{
		int n;
		std::cin >> n;
		data.resize(n);

		for (int i = 0; i < n; i++)
		{
			std::cin >> data[i];
		}
	}

	/*
	Perform the min heap sort algorithm
	1) Loop begins by setting parent, left_child, and right_child
	2) Each iteration checks if last index is smaller than left_child and/or right_child of parent node
	3) Each iteration will finish by comparing parent node with left_child
	4) End of each iteration moves last index forward by 1; last node assumed to be in the final location
	*/
	void GenerateSwaps()
	{
		int last_index = static_cast<int>(data.size()) - 1;
		int parent = 0, left_child = 0, right_child = 0;

		for (int i = 0; i < last_index; i++)
		{
			parent      = floor(i / 2);
			left_child  = parent * 2 + 1;
			right_child = parent * 2 + 2;

			if (left_child < last_index && data[last_index] < data[left_child])
			{
				std::swap(data[left_child], data[last_index]);
				swaps.push_back(std::make_pair(left_child, last_index));
			}

			if (right_child < last_index && data[last_index] < data[right_child])
			{
				std::swap(data[right_child], data[last_index]);
				swaps.push_back(std::make_pair(right_child, last_index));
			}

			if (left_child < data.size() && data[parent] > data[left_child])
			{
				std::swap(data[parent], data[left_child]);
				swaps.push_back(std::make_pair(parent, left_child));
			}

			last_index--;
		}
	}

public:
	void Solve()
	{
		ReadData();
		GenerateSwaps();
		WriteResponse();
	}
};


/*
Input:
A) Integer on first line to represent vector size
B) N integers on the second line to populate the vector
Output:
A) The minimum swaps needed to build a min heap
B) A list of all of the swaps that had taken place
*/
int main()
{
	HeapBuilder heap_builder;
	heap_builder.Solve();

	system("pause");
	return 0;
}