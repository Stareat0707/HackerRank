#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	long id;
	set<int> others;
	int dist;
};

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val)
{
	map<int, Node> graph;
	set<int> starts;

	for (int i = 0; i < graph_from.size(); ++i)
	{
		graph[graph_from[i]].id = ids[graph_from[i] - 1];
		graph[graph_from[i]].others.insert(graph_to[i]);

		if (graph[graph_from[i]].id == val)
			starts.insert(graph_from[i]);

		graph[graph_to[i]].id = ids[graph_to[i] - 1];
		graph[graph_to[i]].others.insert(graph_from[i]);

		if (graph[graph_to[i]].id == val)
			starts.insert(graph_to[i]);
	}

	int result = -1;
	for (int start : starts)
	{
		map<int, bool> visit;

		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			if (visit[node])
				continue;
			else
				visit[node] = true;

			if (node != start && graph[node].id == val)
			{
				result == -1 ? result = graph[node].dist : result = min(result, graph[node].dist);
				break;
			}

			for (int next : graph[node].others)
			{
				graph[next].dist = graph[node].dist + 1;
				q.push(next);
			}
		}

		if (result == 1 || result == -1)
			break;
	}

	return result;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> graph_from(m), graph_to(m);
	for (int i = 0; i < m; ++i)
		cin >> graph_from[i] >> graph_to[i];

	vector<long> ids(n);
	for (int i = 0; i < n; ++i)
		cin >> ids[i];

	int val;
	cin >> val;

	cout << findShortest(n, graph_from, graph_to, ids, val) << endl;
	return 0;
}
