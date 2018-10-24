#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Workshop
{
	int start_time;
	int duration;
	int end_time;
};

struct Available_Workshops
{
	int n;
	vector<Workshop> workshops;

	Available_Workshops(int n) :
		n(n)
	{
		workshops.resize(n);
	}
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
	Available_Workshops* aw = new Available_Workshops(n);
	for (int i = 0; i < n; ++i)
	{
		aw->workshops[i].start_time = start_time[i];
		aw->workshops[i].duration = duration[i];
		aw->workshops[i].end_time = start_time[i] + duration[i];
	}

	return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
	sort(ptr->workshops.begin(), ptr->workshops.end(), [](Workshop& a, Workshop& b) { return a.end_time < b.end_time; });

	int result = 0;
	map<int, bool> visit;
	for (int i = 0; i < ptr->n; ++i)
	{
		bool flag = false;
		for (int j = ptr->workshops[i].start_time; j < ptr->workshops[i].end_time; ++j)
		{
			if (visit[j])
			{
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		for (int j = ptr->workshops[i].start_time; j < ptr->workshops[i].end_time; ++j)
			visit[j] = true;

		++result;
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> start_time[i];

	for (int i = 0; i < n; ++i)
		cin >> duration[i];

	Available_Workshops* ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
	return 0;
}
