#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string abbreviation(string a, string b)
{
	vector<vector<bool>> dp(a.size() + 1);
	for (int i = 0; i <= a.size(); ++i)
		dp[i].resize(b.size() + 1);

	dp[0][0] = true;

	for (int i = 0; i < a.length(); ++i)
	{
		for (int j = 0; j <= b.length(); ++j)
		{
			if (dp[i][j])
			{
				if (j < b.length() && toupper(a[i]) == b[j])
					dp[i + 1][j + 1] = true;

				if (a[i] < 'A' || a[i] > 'Z')
					dp[i + 1][j] = true;
			}
		}
	}

	return (dp[a.length()][b.length()] ? "YES" : "NO");
}

int main()
{
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		string a;
		cin >> a;

		string b;
		cin >> b;

		cout << abbreviation(a, b) << endl;
	}

	return 0;
}
