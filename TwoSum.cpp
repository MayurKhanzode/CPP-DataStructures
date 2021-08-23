#include "TwoSum.h"
/*
PROBLEM:
	Return the indices of the elements from an array for which the sum is equal to the given number
	Ex. arr[] = {2,5,11,17}
	Number = 22
	Return : {5,17}
	Use best possible complexity
*/

/*
	Simple solution : for( auto i: arr)
						for (auto j: arr)
							if(i!=j)
							   if(arr[i]+arr[j] == NUMBER) return {i,j}
	Complexity : O(n*n)

	Best Solution:	a) Sort array
					b) Search with i = 0 and j = n-1
						while(i<j)
							if (arr[i]+arr[j] == NUMBER) return 
							else if (arr[i]+arr[j] < NUMBER) ++i;
							else --j;
	Complexity : O(nlogn) (i.e. complexity of sorting). Complexity of check O(n).
*/

/*
Note: in best case, as sorting displaces the original position in the array, use vector of pairs to save the 
	positions before sorting, where elements in pair are <Element value, original index>
*/

std::vector<int> TwoSumSolution::findTwoSum(std::vector<int>& arr, int Target)
{
		std::vector<std::pair<int, int>> InputSet;
		for (int i = 0; i < arr.size(); ++i)
			InputSet.push_back(std::make_pair(arr[i], i));

		std::sort(InputSet.begin(), InputSet.end());

		int i = 0, j = arr.size() - 1;
		while (i < j)
		{
			if (InputSet[i].first + InputSet[j].first == Target)
				return { InputSet[i].second, InputSet[j].second };
			else if (InputSet[i].first + InputSet[j].first < Target)
				++i;
			else 
				--j;
		}
		return { -1,-1 };
}
