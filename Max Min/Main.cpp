#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxMin(int k, vector<int> arr)
{
	sort(arr.begin(), arr.end());

	int min = arr[k - 1] - arr[0];
	for (int i = 1; i <= arr.size() - k; ++i)
	{
		if (arr[i + k - 1] - arr[i] < min)
		{
			min = arr[i + k - 1] - arr[i];

			if (min == 0)
				break;
		}
	}

	return min;
}

int main()
{
	int n;
	cin >> n;

	int k;
	cin >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << maxMin(k, arr) << endl;
	return 0;
}
