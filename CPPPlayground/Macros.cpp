#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

void DoMacroStuff()
{
	LOG("Hello");
	std::cin.get();
}