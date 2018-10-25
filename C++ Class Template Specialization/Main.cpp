#include <iostream>

using namespace std;

enum class Fruit
{
	apple,
	orange,
	pear
};

enum class Color
{
	red,
	green,
	orange
};

template <typename T> struct Traits;

template <>
struct Traits <Fruit>
{
	static const char* name(int index)
	{
		switch (static_cast<Fruit>(index))
		{
		case Fruit::apple:
			return "apple";
		case Fruit::orange:
			return "orange";
		case Fruit::pear:
			return "pear";
		default:
			return "unknown";
		}
	}
};

template <>
struct Traits <Color>
{
	static const char* name(int index)
	{
		switch (static_cast<Color>(index))
		{
		case Color::red:
			return "red";
		case Color::green:
			return "green";
		case Color::orange:
			return "orange";
		default:
			return "unknown";
		}
	}
};

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i != t; ++i)
	{
		int index1, index2;
		cin >> index1 >> index2;

		cout << Traits<Color>::name(index1) << " ";
		cout << Traits<Fruit>::name(index2) << "\n";
	}
}
