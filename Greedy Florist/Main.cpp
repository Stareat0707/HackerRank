#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getMinimumCost(int k, vector<int> c)
{
	sort(c.rbegin(), c.rend());

	int cost = 0;
	for (int i = 0, count = 0; i < c.size(); i += k, ++count)
	{
		for (int j = k - 1; j >= 0; --j)
		{
			if (i + j >= c.size())
				continue;

			cost += (count + 1) * c[i + j];
		}
	}

	return cost;
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> c(n);
	for (int i = 0; i < n; ++i)
		cin >> c[i];

	cout << getMinimumCost(k, c) << endl;
	return 0;
}
