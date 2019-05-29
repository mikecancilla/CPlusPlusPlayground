#include <iostream>

void DoMultiDimensionalArrays()
{
	// Non-Consolidated Heap version

	// Two dimensional array
	int** a2d = new int*[5];
	for (int i = 0; i < 5; i++)
		a2d[i] = new int[5];

	a2d[0][0] = 0;
	a2d[0][1] = 0;

	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			a2d[x][y] = 2;

	for (int i = 0; i < 5; i++)
		delete[] a2d[i];
	delete[] a2d;

	// Three dimensional array
	int*** a3d = new int**[5];
	for (int i = 0; i < 5; i++)
	{
		a3d[i] = new int*[5];
		for (int j = 0; j < 5; j++)
			a3d[i][j] = new int[5];
	}

	a3d[0][0][0] = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			delete[] a3d[i][j];

		delete[] a3d[i];
	}

	delete[] a3d;

	// Consolidated Heap Version

	// 2D array
	int* array = new int[5 * 5];
	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			array[x + (y * 5)] = 2;

	std::cin.get();
}