#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

long long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
	if (c_lib < c_road)
		return (long long)n * c_lib;

	map<int, set<int>> graph;
	map<int, bool> visit;
	for (int i = 1; i <= n; ++i)
		graph[i], visit[i];

	for (auto& city : cities)
	{
		graph[city[0]].insert(city[1]);
		graph[city[1]].insert(city[0]);
	}

	long long result = 0;
	while (!graph.empty())
	{
		queue<int> q;
		q.push((*graph.begin()).first);

		result += c_lib;
		while (!q.empty())
		{
			int city = q.front();
			q.pop();

			if (visit[city])
				result -= c_road;
			else
				visit[city] = true;

			for (int v : graph[city])
			{
				q.push(v);
				result += c_road;
			}

			graph.erase(city);
		}
	}

	return result;
}

int main()
{
	int q;
	cin >> q;

	while (q--)
	{
		int n, m, c_lib, c_road;
		cin >> n >> m >> c_lib >> c_road;

		vector<vector<int>> cities(m);
		for (int i = 0; i < m; ++i)
		{
			cities[i].resize(2);
			cin >> cities[i][0] >> cities[i][1];
		}

		cout << roadsAndLibraries(n, c_lib, c_road, cities) << endl;
	}

	return 0;
}
