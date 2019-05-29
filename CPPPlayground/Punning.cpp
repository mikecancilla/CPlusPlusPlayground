#include <iostream>

struct Entity
{
	int x, y;

	int* GetPositions()
	{
		return &x;
	}
};

void DoPunning()
{
	int a = 50;
	double value = *(double*)&a;

	std::cout << value << std::endl;

	Entity e = { 5, 8 };

	int* position = e.GetPositions();
	position[0] = 2;

	//int* position = (int*)&e;
	std::cout << position[0] << ", " << position[1] << std::endl;

	int y = *(int*)((char*)&e + 4);
	std::cout << y << std::endl;

	std::cin.get();
}