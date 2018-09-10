#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

long substrCount(int n, string s)
{
	long result = 0;

	vector<int> same_char_count(n);

	for (int i = 0; i < n;)
	{
		int count = 1;

		int j;
		for (j = i + 1; j < n && s[i] == s[j]; ++j)
			++count;

		result += count * (count + 1) >> 1;
		same_char_count[i] = count;
		i = j;
	}

	for (int i = 1; i < n - 1; ++i)
	{
		if (s[i] == s[i - 1])
			same_char_count[i] = same_char_count[i - 1];

		if (s[i - 1] == s[i + 1] && s[i] != s[i - 1])
			result += min(same_char_count[i - 1], same_char_count[i + 1]);
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	cout << substrCount(n, s) << endl;
	return 0;
}