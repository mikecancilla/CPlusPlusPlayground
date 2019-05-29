#include <iostream>
#include <vector>
#include <algorithm> // std::sort
#include <functional> // std::greater

void DoSorting()
{
	std::vector<int> values = { 3, 5, 1, 4, 2 };
//	std::sort(values.begin(), values.end(), std::greater<int>());
//	std::sort(values.begin(), values.end(), [](const int& a, const int& b) { return a < b; });
	std::sort(values.begin(), values.end(), [](const int& a, const int& b)
	{
		if (a == 1)
			return false;
		if (b == 1)
			return true;

		return a < b;
	});

	for (int value : values)
		std::cout << value << std::endl;

	std::cin.get();
}