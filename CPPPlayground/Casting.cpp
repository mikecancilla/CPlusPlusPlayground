#include <iostream>

class Base
{
public:
	Base() {}
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() {}
	~Derived() {}
};

class AnotherClass : public Base
{
public:
	AnotherClass() {}
	~AnotherClass() {}
};

void DoCasting()
{
	// C Style
	double value = 5.25;
	double a = (int)value + 5.3;

	// C++ style
	double s = static_cast<int>(value) + 5.3;

	// double s = static_cast<AnotherClass*>(value) + 5.3; // Invalid type conversion
	// double s = reinterpret_cast<AnotherClass*>(&value) + 5.3; // C Style Cast, type punning

	Derived* derived = new Derived();

	Base* base = derived;

	Derived* ac = dynamic_cast<Derived*>(base);
}