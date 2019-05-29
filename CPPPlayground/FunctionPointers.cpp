#include <iostream>
#include <vector>

void HelloWorld(int a)
{
	std::cout << "Hello World! Value: " << a << std::endl;
}

void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

void DoFunctionPointers()
{
	//HelloWorld();

	typedef void(*HelloWorldFunction)(int a);

	HelloWorldFunction f = HelloWorld;
	f(8);
	f(2);
	f(3);
	f(10);

	//	void(*function)();
//	function = HelloWorld;

//	auto function = HelloWorld;

//	function();

	std::vector<int> values = { 1, 5, 4, 2, 3 };
	ForEach(values, PrintValue);

	// Lambda
	ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });

	std::cin.get();
}