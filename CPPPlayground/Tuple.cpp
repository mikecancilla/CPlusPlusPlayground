#include <string>
#include <tuple>
#include <iostream>

std::tuple<std::string, std::string> GetTuple()
{
	return std::make_tuple("hello", "There");
}

void DoTupleStuff()
{
	std::tuple<std::string, std::string> strings = GetTuple();

	std::string s1 = std::get<0>(strings);
	std::string s2 = std::get<1>(strings);
}