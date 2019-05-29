#include <iostream>

struct Vector2
{
	float x, y;
};

struct Vector4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};
};

/*
struct Vector4
{
	float x, y, z, w;

	Vector2& GetA()
	{
		return *(Vector2*)&x;
	}
};
*/

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

void DoUnions()
{
	struct Union
	{
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;
	std::cout << u.a << ", " << u.b << std::endl;

	Vector4 vector = {1.f, 2.f, 3.f, 4.f};
	PrintVector2(vector.a);
	PrintVector2(vector.b);
	std::cout << "----------------------" << std::endl;
	vector.z = 500.f;
	PrintVector2(vector.a);
	PrintVector2(vector.b);

	std::cin.get();
}
