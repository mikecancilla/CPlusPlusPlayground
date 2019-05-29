#include <iostream>
#include <string>

namespace apple {

	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}

	void print_again() {}
}

namespace orange {

	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << text << std::endl;
	}
}

void DoNamespaceStuff()
{
	namespace a = apple; // so now you just type a::print

	using apple::print;
	print("Hello");
	apple::print_again();

	std::cin.get();
}