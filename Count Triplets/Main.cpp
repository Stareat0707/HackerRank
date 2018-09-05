#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

unsigned long long countTriplets(vector<long> arr, long r)
{
	map<unsigned long long, unsigned long long> left, right;
	for (auto& i : arr)
		++right[i];

	unsigned long long result = 0;
	for (auto& i : arr)
	{
		--right[i];

		if (i % r == 0)
			result += left[i / r] * right[i * r];

		++left[i];
	}

	return result;
}

int main()
{
	int n;
	long r;
	cin >> n >> r;

	vector<long> arr(n);
	for (auto& i : arr)
		cin >> i;

	cout << countTriplets(arr, r) << endl;
	return 0;
}
