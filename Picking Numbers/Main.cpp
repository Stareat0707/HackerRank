#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int pickingNumbers(vector<int>& a)
{
	int result = 0;
	map<int, int> m;
	for (auto& n : a)
	{
		++m[n];
		result = max(result, max(m[n - 1] + m[n], m[n] + m[n + 1]));
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cout << pickingNumbers(a) << endl;
	return 0;
}
