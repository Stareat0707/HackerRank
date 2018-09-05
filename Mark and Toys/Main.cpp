#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maximumToys(vector<int> prices, int k)
{
	sort(prices.begin(), prices.end());

	int count = 0;
	for (auto& price : prices)
	{
		if (k - price >= 0)
		{
			k -= price;
			++count;
		}
		else
			break;
	}

	return count;
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> prices(n);
	for (int i = 0; i < n; ++i)
		cin >> prices[i];

	cout << maximumToys(prices, k) << endl;
	return 0;
}
