#include <iostream>

unsigned int FibMemoizedBottomUp(unsigned int n)
{
	if (n == 1 || n == 2)
		return 1;

	unsigned int *pbu = new unsigned int[n + 1];

	pbu[1] = 1;
	pbu[2] = 1;

	for (unsigned int i = 3; i <= n; i++)
		pbu[i] = pbu[i - 1] + pbu[i - 2];

	unsigned int result = pbu[n];

	delete[] pbu;
	
	return result;
}

unsigned int FibMemoized(unsigned int n, unsigned int* memo)
{
	if (memo[n])
		return memo[n];

	unsigned int result = 0;

	if (n == 1 || n == 2)
		result = 1;
	else
		result = FibMemoized(n - 1, memo) + FibMemoized(n - 2, memo);

	memo[n] = result;
	return result;
}

unsigned int Fib(unsigned int n)
{
	unsigned int result = 0;

	if (n == 1 || n == 2)
		result = 1;
	else
		result = Fib(n - 1) + Fib(n - 2);

	return result;
}

void DoFibonacci(unsigned int n)
{
	//std::cout << "Fib(" << n << ") = " << Fib(n) << std::endl;
	//std::cin.get();

	unsigned int* memo = new unsigned int[n+1];
	memset(memo, 0, sizeof(unsigned int) * (n + 1));

	std::cout << "FibMemoized(" << n << ") = " << FibMemoized(n, memo) << std::endl;

	std::cin.get();

	delete[] memo;

	std::cout << "FibMemoizedBottomUp(" << n << ") = " << FibMemoizedBottomUp(n) << std::endl;

	std::cin.get();
}