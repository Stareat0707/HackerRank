#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
public:
	Graph(int n)
	{
		graph.resize(n);

		for (int i = 0; i < n; ++i)
			distances.push_back(-1);
	}

	void add_edge(int u, int v)
	{
		graph[u].insert(v);
		graph[v].insert(u);
	}

	vector<int> shortest_reach(int start)
	{
		vector<bool> visit(graph.size());
		visit[start] = true;

		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			if (distances[node] == -1)
				distances[node] = 0;

			for (int v : graph[node])
			{
				if (!visit[v])
				{
					visit[v] = true;
					q.push(v);
					distances[v] = distances[node] + 6;
				}
			}
		}

		distances.erase(distances.begin() + start);

		return distances;
	}

	vector<set<int>> graph;
	vector<int> distances;
};

int main()
{
	int q;
	cin >> q;

	while(q--)
	{
		int n, m;
		cin >> n;

		Graph graph(n);
		cin >> m;

		for (int i = 0; i < m; ++i)
		{
			int u, v;
			cin >> u >> v;
			--u, --v;

			graph.add_edge(u, v);
		}

		int startId;
		cin >> startId;
		--startId;

		vector<int> distances = graph.shortest_reach(startId);

		for (int i = 0; i < distances.size(); i++)
				cout << distances[i] << " ";

		cout << endl;
	}

	return 0;
}
