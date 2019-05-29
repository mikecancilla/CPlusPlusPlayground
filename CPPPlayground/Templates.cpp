#include <iostream>

// Function Template

template<typename T>
void Print(T value)
{
	std::cout << value << std::endl;
}

// Class Template

template<int N>
class Array
{
private:
	int m_Array[N];
public:
	int GetSize() const { return N; }
};

template<typename T, int N>
class Array2
{
private:
	T m_Array[N];
public:
	int GetSize() const { return N; }
};

void DoTemplateStuff()
{
	Print(5);
	Print("Hello");
	Print(5.5f);

	Array<7> array;
	std::cout << array.GetSize() << std::endl;

	Array2<int, 9> array2;
	std::cout << array2.GetSize() << std::endl;

	std::cin.get();
}