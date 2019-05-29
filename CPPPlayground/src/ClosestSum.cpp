#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <set>

struct Pair
{
	int i1, i2;
};

Pair FindClosestPairBruteForce(int* a1, int* a2, unsigned int size, int target)
{
	Pair closestPair = { 0, 0 };
	unsigned int closestDiff = UINT_MAX;

	for (int i=0; i<size; i++)
		for (int j=0; j<size; j++)
		{
			if (abs(target - (a1[i] + a2[j])) < closestDiff)
			{
				closestPair.i1 = a1[i];
				closestPair.i2 = a2[j];
				closestDiff = target - (closestPair.i1 + closestPair.i2);

				std::cout << "Closest Diff=" << closestDiff << " " << closestPair.i1 << "," << closestPair.i2 << std::endl;

				if (closestDiff == 0)
					return closestPair;
			}
		}

	return closestPair;
}

Pair FindClosestPairVec(const std::vector<int>& a1, const std::vector<int>& a2, int target)
{
	Pair closestPair = { 0, 0 };
	unsigned int closestDiff = UINT_MAX;

	for (const int& i : a1)
		for (const int& j : a2)
	//for (int i = 0; i<a1.size(); i++)
		//for (int j = 0; j<a2.size(); j++)
		{
			if (abs(target - (i + j)) < closestDiff)
			{
				closestPair.i1 = i;
				closestPair.i2 = j;
				closestDiff = target - (i + j);

				std::cout << "Closest Diff=" << closestDiff << " " << i << "," << j << std::endl;

				if (closestDiff == 0)
					return closestPair;
			}
		}

	return closestPair;
}

Pair FindClosestPairVecSet(const std::vector<int>& a1, const std::vector<int>& a2, int target)
{
	Pair closestPair = { 0, 0 };
	unsigned int closestDiff = UINT_MAX;
	std::unordered_set<int> us;

	for (const int& i : a1)
		us.insert(i);

	int t1 = target;
	int t2 = target - 1;

	for (;;)
	{
		for (const int& j : a2)
		{
			std::unordered_set<int>::iterator got = us.find(t1 - j);
			if (got != us.end())
			{
				closestPair.i1 = *got;
				closestPair.i2 = j;
				return closestPair;
			}

			got = us.find(t2 - j);
			if (got != us.end())
			{
				closestPair.i1 = *got;
				closestPair.i2 = j;
				return closestPair;
			}
		}

		t1++;
		t2--;
	}

	return closestPair;
}

void DoClosestSum()
{
	int a1[6] = { -1, 3, 8, 2, 9, 5 };
	int a2[6] = { 4, 1, 2, 10, 5, 20 };
	int target = 24;

	std::set<int> set = { -1, 3, 8, 2, 9, 5 };
	std::unordered_set<int> us = { -1, 3, 8, 2, 9, 5 };

	Pair p = FindClosestPairBruteForce(a1, a2, 6, target);
	std::cout << "Pair BruteForce closest to " << target << " is: " << p.i1 << "," << p.i2 << std::endl;

	std::vector<int> v1 = { -1, 3, 8, 2, 9, 5 };
	std::vector<int> v2 = { 4, 1, 2, 10, 5, 20 };

	p = FindClosestPairVec(v1, v2, target);
	std::cout << "Pair Vec closest to " << target << " is: " << p.i1 << "," << p.i2 << std::endl;

	p = FindClosestPairVecSet(v1, v2, target);
	std::cout << "Pair VecSet closest to " << target << " is: " << p.i1 << "," << p.i2 << std::endl;
}