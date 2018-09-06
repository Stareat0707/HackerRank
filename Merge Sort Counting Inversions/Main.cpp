#include <iostream>
#include <vector>

using namespace std;

long mergeSort(vector<int>& arr, int left, int right, vector<int>& result)
{
	if (left >= right)
		return 0;

	int mid = (left + right) / 2;

	long count = mergeSort(arr, left, mid, result);
	count += mergeSort(arr, mid + 1, right, result);

	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			result[k++] = arr[i++];
		else
		{
			result[k++] = arr[j++];
			count += j - k;
		}
	}

	while (i <= mid)
		result[k++] = arr[i++];

	while (j <= right)
		result[k++] = arr[j++];

	for (int i = left; i <= right; ++i)
		arr[i] = result[i];

	return count;
}

long countInversions(vector<int> arr)
{
	vector<int> result(arr);
	return mergeSort(arr, 0, arr.size() - 1, result);
}

int main()
{
	int d;
	cin >> d;

	for (int i = 0; i < d; ++i)
	{
		int n;
		cin >> n;

		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		cout << countInversions(arr) << endl;
	}

	return 0;
}