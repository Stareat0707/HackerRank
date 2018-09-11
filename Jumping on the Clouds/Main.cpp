#include <iostream>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c)
{
	int count = 0;

	for (int i = 0; i < c.size() - 1; ++i)
	{
		if (i + 2 < c.size() && c[i] != 1)
			++i;

		++count;
	}

	return count;
}

int main()
{
	int n;
	cin >> n;

	vector<int> c(n);
	for (int i = 0; i < n; ++i)
		cin >> c[i];

	cout << jumpingOnClouds(c) << endl;
	return 0;
}
