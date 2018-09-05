#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int activityNotifications(vector<int> expenditure, int d)
{
	int count = 0;
	map<int, int> freq;

	for (int i = 0; i < d; ++i)
		++freq[expenditure[i]];

	for (int i = d; i < expenditure.size(); ++i)
	{
		int temp = 0;
		double median;
		for (auto& f : freq)
		{
			temp += f.second;
			if (temp >= d / 2 + d % 2)
			{
				median = f.first;
				break;
			}
		}

		if (d % 2 == 0)
		{
			temp = 0;
			for (auto& f : freq)
			{
				temp += f.second;
				if (temp >= d / 2 + 1)
				{
					median += f.first;
					median /= 2.0;
					break;
				}
			}
		}

		if (expenditure[i] >= median * 2)
			++count;

		--freq[expenditure[i - d]];
		++freq[expenditure[i]];
	}

	return count;
}

int main()
{
	ifstream in("input.txt");

	int n, d;
	// cin >> n >> d;
	in >> n >> d;

	vector<int> expenditure(n);
	for (int i = 0; i < n; ++i)
		// cin >> expenditure[i];
		in >> expenditure[i];

	cout << activityNotifications(expenditure, d) << endl;
	return 0;
}
