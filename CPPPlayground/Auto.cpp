#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string GetName()
//auto GetName() // C++ 14
//auto GetName -> char * // C++ 11
{
	return "Cancilla";
}

class Device
{

};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};

void DoAutoStuff()
{
	auto name = GetName();

	int a = name.size(); // Careful here, you are assuming a std::string

	std::cout << name << " " << a << std::endl;

	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

//	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;

	DeviceManager dm;
	const DeviceMap& devices = dm.GetDevices();
	const auto& devices2 = dm.GetDevices();

	std::cin.get();
}