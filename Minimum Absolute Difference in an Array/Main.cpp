#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minimumAbsoluteDifference(vector<int> arr)
{
	sort(arr.rbegin(), arr.rend());

	int min = arr[0] - arr[1];
	for (int i = 2; i < arr.size(); ++i)
	{
		if (arr[i - 1] - arr[i] < min)
			min = arr[i - 1] - arr[i];
	}

	return min;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for (auto& i : arr)
		cin >> i;

	cout << minimumAbsoluteDifference(arr) << endl;
	return 0;
}
