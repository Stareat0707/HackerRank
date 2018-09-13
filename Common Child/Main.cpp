#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int commonChild(string s1, string s2)
{
	vector<vector<int>> dp(s1.size() + 1);
	for (auto& v : dp)
		v.resize(s2.size() + 1);

	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[s1.size()][s2.size()];
}

int main()
{
	string s1;
	cin >> s1;

	string s2;
	cin >> s2;

	cout << commonChild(s1, s2) << endl;
	return 0;
}
