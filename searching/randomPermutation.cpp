#include <iostream>
#include <random>
#include <vector>
#include <math.h>

void getCandidates(std::vector <int> &candidate_ranks);
std::pair<int, int> randomizedHireAssistant(std::vector <int> &candidate_ranks);


/*
Input:  number of candidates available for hire
Output: the best candidate within the list, and where in the list the candidate exists
*/
int main()
{
    std::vector<int> candidate_ranks;
    getCandidates(candidate_ranks);
    std::pair<int, int> best = randomizedHireAssistant(candidate_ranks);
    
    std::cout << "The best candidate is " << best.first <<
                 " who is number "        << best.second + 1 <<
                 " on the list."          << std::endl;
    
    return 0;
}


int getRandomNumber(int min, int max)
{
    static std::random_device randomized;
    static std::mt19937 mersenne{ randomized() };
    static const double fraction = 1.0 / (static_cast<double>(mersenne.max()) + 1.0);
    return min + static_cast<int>((max - min + 1) * (mersenne() * fraction));
}


void getCandidates(std::vector <int> &candidate_ranks)
{
    std::cout << "Enter the number of candidates on the list: " << std::endl;
    int candidates = 0;
    std::cin >> candidates;
    
    candidate_ranks.resize(candidates);
    
    for (auto &candidate : candidate_ranks)
    {
        candidate = getRandomNumber(1, 100);
    }
}


void presentCandidateList(std::vector<int> &candidate_ranks)
{
    std::cout << "The available candidates on the list are: " <<std::endl;
    
    for (auto &candidate : candidate_ranks)
    {
        std::cout << candidate << " ";
    }
    
    std::cout << std::endl;
}


/*
Make the algorithm itself randomized so every permutation in which
the candidates are presented is equally likely.
This makes it so no particular input elicits its worst-case behavior (no assumption made).
The below method performs this randomized permuation in O(n).
*/
void randomInPlace(std::vector <int> &candidate_ranks)
{
    for (int index = 0; index < candidate_ranks.size(); index++)
    {
        std::swap( candidate_ranks[index], candidate_ranks[getRandomNumber(index, static_cast<int>(candidate_ranks.size() - 1))] );
    }
    
    presentCandidateList(candidate_ranks);
}


// Find the best candidate and at what index in the list the candidate can be found
std::pair<int, int> randomizedHireAssistant(std::vector <int> &candidate_ranks)
{
    randomInPlace(candidate_ranks);
    
    int best = 0;
    
    for (int index = 1; index < candidate_ranks.size(); index++)
    {
        if (candidate_ranks[index] > candidate_ranks[best])
        {
            best = index;
        }
    }
    
    return std::pair<int, int>(std::make_pair(candidate_ranks[best], best));
}
