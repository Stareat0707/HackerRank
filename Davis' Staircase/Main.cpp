#include <iostream>
#include <vector>

using namespace std;

int stepPerms(int n, vector<int>& dp)
{
	if (n == 0)
		return 1;

	if (n < 0)
		return 0;

	if (dp[n] != -1)
		return dp[n];
	dp[n] = stepPerms(n - 1, dp) % 10000000007;
	dp[n] = (dp[n] + stepPerms(n - 2, dp)) % 10000000007;
	dp[n] = (dp[n] + stepPerms(n - 3, dp)) % 10000000007;
	return dp[n];
}

int main()
{
	int s;
	cin >> s;

	vector<int> dp(100001, -1);
	for (int i = 0; i < s; ++i)
	{
		int n;
		cin >> n;

		cout << stepPerms(n, dp) << endl;
	}

	return 0;
}
