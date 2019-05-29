#include <iostream>
#include <vector>
#include <bitset>

unsigned int FindNumSets(const std::vector<unsigned int>& set, unsigned int target)
{
	if (target == 0)
		return 1;

	unsigned int numFoundSets = 0;

	unsigned int loopCount = 1 << set.size();

	for (unsigned int i = 1; i < loopCount; i++)
	{
		unsigned int j = i;
		unsigned int index = 0;
		unsigned int sum = 0;

		while (j)
		{
			if (j & 1)
			{
				if (set[index] + sum == target)
					numFoundSets++;

				sum += set[index];
			}

			index++;
			j >>= 1;
		}
	}

	return numFoundSets;
}

void DoSubSets()
{
	std::vector<unsigned int> set = { 2, 4, 5, 6, 9, 10 };

	unsigned int target = 16;
	std::cout << "DoSubSets(" << target << ")=" << FindNumSets(set, target) << std::endl;
	std::cin.get();
}