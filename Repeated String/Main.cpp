#include <iostream>
#include <string>

using namespace std;

long repeatedString(string s, long n)
{
	long count = 0;
	for (char c : s)
	{
		if (c == 'a')
			++count;
	}

	count *= n / s.size();

	for (int i = 0; i < n % s.size(); ++i)
	{
		if (s[i] == 'a')
			++count;
	}

	return count;
}

int main()
{
	string s;
	cin >> s;

	int n;
	cin >> n;

	cout << repeatedString(s, n) << endl;
	return 0;
}
