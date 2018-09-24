#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long maximumSum(vector<long> a, long m)
{
	set<long> s;
	s.insert(0);
	long prefix = 0, maxim = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		prefix = (prefix + a[i]) % m;
		maxim = max(maxim, prefix);
		set<long>::iterator  it = s.lower_bound(prefix + 1);
		if (it != s.end())
			maxim = max(maxim, prefix - (*it) + m);
		s.insert(prefix);
	}

	return maxim;
}

int main()
{
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i);
	{
		int n;
		long m;
		cin >> n >> m;

		vector<long> a(n);
		for (auto& ai : a)
			cin >> ai;

		cout << maximumSum(a, m) << endl;
	}

	return 0;
}
