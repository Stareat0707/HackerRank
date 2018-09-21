#include <iostream>
#include <map>
#include <vector>

using namespace std;

int pairs(int k, vector<int> arr)
{
	map<int, bool> m;
	for (int i = 0; i < arr.size(); ++i)
		m[arr[i]] = true;

	int count = 0;
	for (auto& p : m)
	{
		if (m[p.first + k] != 0)
			++count;
		else
			m.erase(p.first + k);
	}

	return count;
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << pairs(k, arr) << endl;
	return 0;
}
