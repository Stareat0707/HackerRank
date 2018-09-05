#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> freqQuery(vector<vector<int>> queries)
{
	vector<int> result;

	map<int, unsigned long long> mp;
	map<int, int> count;
	for (auto& query : queries)
	{
		switch (query[0])
		{
		case 1:
			count[mp[query[1]]] = max(count[mp[query[1]]] - 1, 0);
			++count[++mp[query[1]]];
			break;

		case 2:
			if (mp[query[1]] > 0)
			{
				count[mp[query[1]]] = max(count[mp[query[1]]] - 1, 0);
				++count[--mp[query[1]]];
			}

			break;

		case 3:
			result.push_back(count[query[1]] > 0 ? 1 : 0);
			break;
		}
	}

	return result;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int q;
	// cin >> q;
	in >> q;

	vector<vector<int>> queries;
	for (int i = 0; i < q; ++i)
	{
		vector<int> query(2);
		// cin >> query[0] >> query[1];
		in >> query[0] >> query[1];
		queries.push_back(query);
	}

	vector<int> result = freqQuery(queries);
	for (auto& n : result)
		out << n << endl;

	in.close();
	out.close();
	return 0;
}
