#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<long> riddle(vector<long> arr)
{
	vector<int> prev(arr.size(), -1);
	vector<int> next(arr.size(), arr.size());

	stack<int> s;
	for (int i = 0; i < arr.size(); ++i)
	{
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();

		if (!s.empty())
			prev[i] = s.top();

		s.push(i);
	}

	while (!s.empty())
		s.pop();

	for (int i = arr.size() - 1; i >= 0; --i)
	{
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();

		if (!s.empty())
			next[i] = s.top();

		s.push(i);
	}

	vector<long> result(arr.size());
	for (int i = 0; i < arr.size(); ++i)
	{
		int len = next[i] - prev[i] - 1;
		result[len - 1] = max(result[len - 1], arr[i]);
	}

	for (int i = arr.size() - 2; i >= 0; --i)
		result[i] = max(result[i], result[i + 1]);

	return result;
}

int main()
{
	int n;
	cin >> n;

	vector<long> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	vector<long> result = riddle(arr);
	for (int i = 0; i < n; ++i)
		cout << result[i] << ' ';

	cout << endl;
	return 0;
}
