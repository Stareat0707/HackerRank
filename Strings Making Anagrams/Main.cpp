#include <iostream>
#include <map>
#include <string>

using namespace std;

int makeAnagram(string a, string b)
{
	int count = 0;
	map<char, int> m;

	for (char c : a)
		++m[c];
	
	for (char c : b)
		--m[c];

	for (auto& p : m)
	{
		if (p.second != 0)
			count += abs(p.second);
	}

	return count;
}

int main()
{
	string a;
	cin >> a;

	string b;
	cin >> b;

	int res = makeAnagram(a, b);

	cout << res << endl;
	return 0;
}
