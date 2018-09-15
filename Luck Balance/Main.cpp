#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int luckBalance(int k, vector<vector<int>> contests)
{
	sort(contests.begin(), contests.end(), [](vector<int>& v1, vector<int>& v2) { return v1[0] > v2[0]; });

	int luck = 0;
	for (int i = 0; i < contests.size(); ++i)
	{
		if (contests[i][1] == 0 || k > 0)
		{
			luck += contests[i][0];

			if (contests[i][1] == 1)
				--k;
		}
		else
			luck -= contests[i][0];
	}

	return luck;
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> contests(n);
	for (int i = 0; i < n; ++i)
	{
		contests[i].resize(2);

		for (int j = 0; j < 2; ++j)
			cin >> contests[i][j];
	}

	cout << luckBalance(k, contests) << endl;
	return 0;
}
