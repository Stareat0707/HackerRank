#include <iostream>
#include <vector>

using namespace std;

long candies(int n, vector<int> arr)
{
	vector<int> candyNum(n);
	candyNum[0] = 1;

	long result = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		candyNum[i + 1] = 1;

		if (arr[i] < arr[i + 1] && candyNum[i] >= candyNum[i + 1])
			candyNum[i + 1] = candyNum[i] + 1;
		else if (arr[i] > arr[i + 1] && candyNum[i] <= candyNum[i + 1])
			candyNum[i] = candyNum[i + 1] + 1;
	}

	for (int i = n - 1; i > 0; --i)
	{
		if (arr[i - 1] < arr[i] && candyNum[i - 1] >= candyNum[i])
			candyNum[i] = candyNum[i - 1] + 1;
		else if (arr[i - 1] > arr[i] && candyNum[i - 1] <= candyNum[i])
			candyNum[i - 1] = candyNum[i] + 1;

		result += candyNum[i];
	}

	result += candyNum[0];
	return result;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	cout << candies(n, arr) << endl;
	return 0;
}
