#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

void whatFlavors(vector<int> cost, int money)
{
	map<int, queue<int>> m;
	for (int i = 0; i < cost.size(); ++i)
	{
		if (cost[i] < money)
			m[cost[i]].push(i);
	}

	for (auto& p : m)
	{
			int id1 = p.second.front();
			p.second.pop();

			if (!m[money - p.first].empty())
			{
				int id2 = m[money - p.first].front();

				if (id1 > id2)
				{
					int temp = id1;
					id1 = id2;
					id2 = temp;
				}

				cout << ++id1 << ' ' << ++id2 << '\n';
				return;
			}
	}
}

int main()
{
	int t;
	cin >> t;

	do
	{
		int money;
		cin >> money;

		int n;
		cin >> n;

		vector<int> cost(n);
		for (int i = 0; i < n; ++i)
			cin >> cost[i];

		whatFlavors(cost, money);
	} while (--t);

	return 0;
}
