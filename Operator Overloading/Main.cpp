#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
	vector<vector<int>> a;

	Matrix operator+(const Matrix& other)
	{
		Matrix result;
		for (int i = 0; i < a.size(); ++i)
		{
			vector<int> b;
			for (int j = 0; j < a[i].size(); ++j)
				b.push_back(a[i][j] + other.a[i][j]);

			result.a.push_back(b);
		}

		return result;
	}
};

int main()
{
	int cases;
	cin >> cases;

	for (int k = 0; k < cases; ++k)
	{
		Matrix x;
		Matrix y;
		Matrix result;

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			vector<int> b;
			int num;
			for (int j = 0; j < m; ++j) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for (int i = 0; i < n; ++i)
		{
			vector<int> b;
			int num;
			for (int j = 0; j < m; ++j)
			{
				cin >> num;
				b.push_back(num);
			}

			y.a.push_back(b);
		}

		result = x + y;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << result.a[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}
