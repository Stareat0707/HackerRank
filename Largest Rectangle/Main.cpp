#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long largestRectangle(vector<int> h)
{
	long result = 0;
	stack<int> s;

	h.push_back(0);
	for (int k = 0; k < h.size(); ++k)
	{
		while (!s.empty() && h[s.top()] > h[k])
		{
			int i = h[s.top()];
			s.pop();

			int j = (s.empty() ? -1 : s.top());

			result = max(result, (long)i * (k - j - 1));
		}

		s.push(k);
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	vector<int> h(n);
	for (int i = 0; i < n; ++i)
		cin >> h[i];

	cout << largestRectangle(h) << endl;
	return 0;
}
