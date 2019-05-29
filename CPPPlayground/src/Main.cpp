#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <memory> // smart pointers

extern void DoDynamicArrayStuff();
extern void DoClosestSum();
extern void DoFibonacci(unsigned int n);
extern void DoSubSets();
extern void DoTupleStuff();
extern void DoTemplateStuff();
extern void DoStackHeapMemory();
extern void DoMacroStuff();
extern void DoAutoStuff();
extern void DoArrayStuff();
extern void DoFunctionPointers();
extern void DoLambda();
extern void DoPunning();
extern void DoUnions();
extern void DoThreads();
extern void DoTiming();
extern void DoMultiDimensionalArrays();
extern void DoSorting();
extern void DoVirtualDestructors();
extern void DoCasting();

// Using like typedef
//using String = std::string;

void PrintString(const std::string& str)
{
	std::cout << "String: " << str << std::endl;
	std::cout << "  Size: " << str.size() << std::endl;
	std::cout << "  Length: " << str.length() << std::endl;
	std::cout << "  Capacity: " << str.capacity() << std::endl;
	std::cout << "  'no' at: " << str.find("no") << std::endl;
}

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;

public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	// Copy Constructor, takes a const reference to the same class
	String(const String& other)
		: m_Size(other.m_Size)
	{
		std::cout << "Copied String!" << std::endl;

		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

class Entity
{
private:
	int m_X, m_Y;
	mutable int var;  // Mutable means something can be changed.  Allows you to modify this inside a const method.
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	// const after function name means method will not modify any class member variables.
	int GetX() const
	{
		int y = 1;
		y = 0;
		return m_X;
	}

	// Return a pointer whos contents cannot be modified, the pointer itself cannot be modfied, and this function will not modify the member variables.
	/*
	const int* const GetX() const
	{
		int y = 1;
		y = 0;
		return m_X;
	}
	*/

	void SetX(int x)
	{
		m_X = x;
	}

	void Print() const { std::cout << "Hello!" << std::endl;  }
};

struct Vector2
{
	float x, y;

	Vector2(float x, float y)
		: x(x), y(x) {}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);

		// Optional ways to call +
		// return *this + other;
		// return operator+(other);
	}

	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const
	{
		return x != other.x || y != other.y;

		// other ways
		// return !(*this == other);
		// return !operator==(other);
	}
};

class ScopedPtr
{
private:
	Entity * m_Obj;

public:
	ScopedPtr(Entity* entity)
		: m_Obj(entity)
	{

	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->()
	{
		return m_Obj;
	}

	const Entity* operator->() const
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z;
};

// operator overloading '<<'
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

void PrintString(const String& string)
{
	std::cout << string << std::endl;
}

///////
// MAIN
///////

int main()
{
	DoCasting();

//	DoVirtualDestructors();

//	DoSorting();

//	DoMultiDimensionalArrays();
		
//	DoTiming();

//  DoThreads();

//	DoUnions();
		
//	DoPunning();

//	DoLambda();

//	DoFunctionPointers();

//	DoArrayStuff();

//	DoAutoStuff();

//	DoMacroStuff();

//	DoStackHeapMemory();

//	DoTemplateStuff();

//	DoTupleStuff();

//	DoSubSets();

//	DoFibonacci(3000);

//	DoClosestSum();

//	DoDynamicArrayStuff();

/*
	// Arrow operator
	ScopedPtr entity = new Entity();
	entity->Print();

	const ScopedPtr entity2 = new Entity();
	entity2->Print();

	// Use arrow operator to figure out offset
	int offset = (int) &((Vector3*)0)->z;
	std::cout << "Offset: " << offset << std::endl;

	// Copy constructors
	String string = "Cancilla";
	String second = string;

	second[1] = 'e';

	std::cout << string << std::endl;
	std::cout << second << std::endl;

	PrintString(string);
	PrintString(second);

	// smart pointers, unique_ptr, shared_ptr, weak_ptr
	{
		//std::unique_ptr<Entity> entity(new Entity()); // One way
		std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // Preferred way

		std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
		std::shared_ptr<Entity> e0 = sharedEntity;
		std::weak_ptr<Entity> weakEntity = sharedEntity; // Weak pointer assignment will not increase the ref count, you can ask a weak pointer if its valid before using it
	}

	// operator overloading
	Vector2 position(4.f, 4.f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiply(powerup));
	Vector2 result2 = position + speed * powerup;

	if(result1 == result2)

	std::cout << result2 << std::endl;

	// std::string
	//std::string name = std::string("Cherno") + " hello!";
    //
	//PrintString(name);
	//
	//bool contains = name.find("no") != std::string::npos;
	//
	//std::cout << name << std::endl;

	// Char types
	const char* name = u8"Cherno";
	const wchar_t* name2 = L"Cherno";
	const char16_t* name3 = u"Cherno";
	const char32_t* name4 = U"Cherno";

	// Const
	const int MAX_AGE = 90;
	int* a = new int;

	// Cannot modify the contents of the pointer: const to left of *
	//  Read from R to L -> a is a pointer to a constant int or int constant
	// const int* a = new int;
	// int const* a = new int;

	*a = 2;

	// Cannot modify a
	//  Read from R to L -> a is a const pointer to an int
	// int* const a = new int;

	a = (int*)&MAX_AGE;

	// Cannot change the contents of the pointer, nor the pointer itself
	// const int* const a = new int;

	std::cout << *a << std::endl;

	// Lambda - a function you can assign to a variable (think JavaScript)
	int x = 8;
	auto f = []() // mutable <- You can put mutable here which allows you to modify parameters
	{
		std::cout << "Hello" << std::endl;
	};

	f();

	// std::iterator
#if 0
	std::vector<int> ar = { 1, 2, 3, 4, 5 };
	std::vector<int> ar1 = { 10, 20, 30 };

	// Declaring iterator to a vector 
	std::vector<int>::iterator ptr = ar.begin();

	// Using advance to set position 
	advance(ptr, 3);

	// copying 1 vector elements in other using inserter() 
	// inserts ar1 after 3rd position in ar 
	copy(ar1.begin(), ar1.end(), inserter(ar, ptr));

	// Displaying new vector elements 
	std::cout << "The new vector after inserting elements is : ";
	for (int &x : ar)
		std::cout << x << " ";
#endif
*/
//	std::cin.get();
}