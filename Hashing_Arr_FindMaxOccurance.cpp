#include <iostream>
#include <vector>
#include <unordered_map>

int getMaxNumberInteger(std::vector<int>& myArr)
{
	std::unordered_map<int, int> myHash;
	for (auto i = 0; i < myArr.size(); i++)
	{
		myHash[myArr.at(i)]++;
	}

	int max = 0;
	int element = -1;
	for (auto x : myHash)
	{
		if (x.second > max)
		{
			max = x.second;
			element = x.first;
		}
	}
	return element;
}

int main()
{
	std::vector<int> myArr{ 1, 1, 1, 2, 2, 4, 4 };
	std::cout << "Maximum occurance number: " << getMaxNumberInteger(myArr) << std::endl;
	return 0;
}
