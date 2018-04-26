#include <iostream>
#include <vector>
#include <math.h>


void buildArrayToSort(std::vector <int> &sortedArray);
void mergeSort(std::vector <int> &sortedArray);
void makeElementCopies(std::vector <int> &sortedArray, std::vector <int> &comparisonArray, int startIndex);
void merge(std::vector <int> &sortedArray, int left, int l_end, int right, int r_end);
void sortSubVectors(std::vector <int> &sortedArray, std::vector <int> &left_array, std::vector <int> &right_array, int left, int l_end, int right, int r_end);
void printSortedArray(std::vector <int> &sortedArray);


int main()
{
    std::vector <int> sortedArray;
    
    buildArrayToSort(sortedArray);
    mergeSort(sortedArray);
    printSortedArray(sortedArray);
    
    //system("pause");
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


void mergeSort(std::vector <int> &sortedArray)
{
    // If only one element in the vector, return becasue it is already sorted
    if (sortedArray.size() < 2) { return; }
    
    int left, right;
    
    // Step through comparison groups in the array via a bottoms-up approach
    // Begin with group comparison of size 1, then double comparison group size each iteration
    for (int step = 1; step < sortedArray.size(); step *= 2)
    {
        /*
        Step represents the comparison group size
        left will always start at the beginning
        right will always start that the beginning of the next step
        */
        left  = 0;
        right = step;
        
        // While the right comparison group does not exceed the size of the vector
        while ((right + step) <= sortedArray.size())
        {
            /*
            Merge sortSubVectors the left and right comparison groups
            March through the vector of sub-vectors to merge sortSubVectors each comparison group
            */
            merge(sortedArray, left, (left + step), right, (right + step));
            left  = right + step;
            right = left + step;
        }
        
        /*
        This will sortSubVectors the last index of the vector if the vector size is odd
        Sonce the step size increases by ^2, an odd vector size will always have a sub-vector of size 1
        */
        if (right < sortedArray.size())
        {
            merge(sortedArray, left, (left + step), right, static_cast<int>(sortedArray.size()));
        }
    }
}


void merge(std::vector <int> &sortedArray, int left, int l_end, int right, int r_end)
{
    // The two comparison groups will create temporary vectors to hold the sorted elements
    std::vector <int> left_array(l_end - left + 1);
    std::vector <int> right_array(r_end - right + 1);
    
    // Copy the elements of the parent array into the temporary comparison groups
    makeElementCopies(sortedArray, left_array, left);
    makeElementCopies(sortedArray, right_array, right);
    
    /*
    Add the sentinel element to the end of each comparison array (int max value)
    This is to keep the comparison sub-vectors in-bounds when iterating through 2 vectors of same size
    If one comparison vector reaches the end its size before another,
    then we can assure that all values in remaining comparison vector will be smaller
    */
    left_array[left_array.size() - 1]   = INT_MAX;
    right_array[right_array.size() - 1] = INT_MAX;
    
    // sortSubVectors the comparison groups
    sortSubVectors(sortedArray, left_array, right_array, left, l_end, right, r_end);
}


void makeElementCopies(std::vector <int> &sortedArray, std::vector <int> &comparisonArray, int startIndex)
{
    for (int index = 0, key = startIndex; index < (comparisonArray.size() - 1); index++, key++)
    {
        comparisonArray[index] = sortedArray[key];
    }
}


void sortSubVectors(std::vector <int> &sortedArray, std::vector <int> &left_array, std::vector <int> &right_array,
          int left, int l_end, int right, int r_end)
{
    for (int key = left, left_index = 0, right_index = 0; key < r_end; key++)
    {
        if (left_array[left_index] <= right_array[right_index])
        {
            sortedArray[key] = left_array[left_index];
            left_index++;
        }
        
        else
        {
            sortedArray[key] = right_array[right_index];
            right_index++;
        }
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
