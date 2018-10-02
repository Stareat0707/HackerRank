#include <iostream>
#include <set>
#include <vector>

using namespace std;

int poisonousPlants(vector<int> p)
{
	set<int> alive, goingToDie, nextToDie;
	alive.insert(0);
	
	for (int i = 1; i < p.size(); ++i)
	{
		alive.insert(i);
		if (p[i - 1] < p[i])
			goingToDie.insert(i);
	}

	int result = 0;
	while (!goingToDie.empty())
	{
		++result;

		for (auto& i : goingToDie)
			alive.erase(i);

		for (auto& i : goingToDie)
		{
			auto it = alive.lower_bound(i);

			if (it == alive.end())
				continue;

			auto prev = it;
			--prev;

			if (p[*prev] < p[*it])
				nextToDie.insert(*it);
		}

		goingToDie = nextToDie;
		nextToDie.clear();
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];

	cout << poisonousPlants(p) << endl;
	return 0;
}
