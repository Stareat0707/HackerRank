#include <iostream>

using namespace std;

int saveThePrisoner(int n, int m, int s)
{
	m %= n;
	m += --s;

	if (m == 0)
		return n;

	if (m > n)
		m %= n;

	return m;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n, m, s;
		cin >> n >> m >> s;

		cout << saveThePrisoner(n, m, s) << endl;
	}

	return 0;
}
