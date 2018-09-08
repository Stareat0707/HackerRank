#include <iostream>
#include <string>

using namespace std;

int alternatingCharacters(string s)
{
	int count = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] == s[i - 1])
			++count;
	}

	return count;
}

int main()
{
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		string s;
		cin >> s;

		cout << alternatingCharacters(s) << endl;
	}

	return 0;
}
