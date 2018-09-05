#include <iostream>
#include <vector>

using namespace std;

void countSwaps(vector<int> a)
{
	int count = 0;

	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a.size() - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				++count;
			}
		}
	}

	cout << "Array is sorted in " << count << " swaps." << endl;
	cout << "First Element: " << a.front() << endl;
	cout << "Last Element: " << a.back() << endl;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	countSwaps(a);
	return 0;
}
