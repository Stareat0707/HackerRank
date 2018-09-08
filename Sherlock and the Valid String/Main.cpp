#include <iostream>
#include <map>
#include <string>

using namespace std;

string isValid(string s)
{
	map<char, int> m0;
	for (char c : s)
		++m0[c];

	map<int, int> m1;
	for (auto& p : m0)
		++m1[p.second];

	if (m1.size() == 1)
		return "YES";

	if (m1.size() > 2)
		return "NO";

	if (m1[1] == 1)
		return "YES";

	for (auto& p : m1)
	{
		if (p.second == 1 && m1[p.first - 1] != 0)
			return "YES";
	}

	return "NO";
}

int main()
{
	string s;
	cin >> s;

	cout << isValid(s) << endl;
	return 0;
}
