#include <iostream>
#include <vector>

using namespace std;

long minTime(vector<long> machines, long goal)
{
	long low = 1;
	long high = 1e18;
	long result = 0;

	while (low <= high)
	{
		long long done = 0;
		long long mid = (low + high) / 2;

		for (int i = 0; i < machines.size(); ++i)
		{
			done += mid / machines[i];
			if (done >= goal)
				break;
		}

		if (done >= goal)
		{
			high = mid - 1;
			result = mid;
		}
		else
			low = mid + 1;
	}

	cout << result << endl;
	return 0;
}

int main()
{
	int n, goal;
	cin >> n >> goal;

	vector<long> machines(n);
	for (int i = 0; i < n; ++i)
		cin >> machines[i];

	cout << minTime(machines, goal) << endl;
	return 0;
}
