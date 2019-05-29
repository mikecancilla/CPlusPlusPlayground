#include <iostream>
#include <array>

void PrintArray(const std::array<int, 5>& data)
{
	for (int i = 0; i < data.size(); i++);
}

void DoArrayStuff()
{
	std::array<int, 5> data;
	data[0] = 2;
	data[4] = 1;

	int dataOld[5];
	dataOld[0] = 3;

    std::cout << data.size() << std::endl;

	std::cin.get();
}