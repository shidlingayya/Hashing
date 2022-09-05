#include <iostream>
#include <vector>
#include <unordered_map>

int firstElemRepeatedTargetTimes(std::vector<int>& myArr, int target)
{
	std::unordered_map<int, int> myHash;
	for (auto i = 0; i < myArr.size(); i++)
	{
		myHash[myArr.at(i)]++;
	}

	int element = -1;
	for (auto x : myHash)
	{
		if (x.second == target)
		{
			element = x.first;
			break;
		}
	}
	return element;
}

int main()
{
	std::vector<int> myArr{ 1, 1, 1, 2, 2, 4, 4 };
	std::cout << "Maximum occurance number: " << firstElemRepeatedTargetTimes(myArr, 2) << std::endl;
	return 0;
}
