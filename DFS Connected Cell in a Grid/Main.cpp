#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dps(vector<vector<int>>& grid, vector<vector<bool>>& visit, int y, int x)
{
	visit[y][x] = true;

	int result = 1;
	for (int i = y - 1; i <= y + 1; ++i)
	{
		if (i < 0 || i >= grid.size())
			continue;

		for (int j = x - 1; j <= x + 1; ++j)
		{
			if (j < 0 || j >= grid[i].size())
				continue;

			if (grid[i][j] == 1 && !visit[i][j])
				result += dps(grid, visit, i, j);
		}
	}

	return result;
}

int maxRegion(vector<vector<int>> grid)
{
	vector<vector<bool>> visit(grid.size());
	for (int i = 0; i < visit.size(); ++i)
		visit[i].resize(grid[i].size());

	int result = 0;
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[i].size(); ++j)
		{
			if (grid[i][j] == 1 && !visit[i][j])
				result = max(result, dps(grid, visit, i, j));
		}
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	int m;
	cin >> m;

	vector<vector<int>> grid(n);
	for (int i = 0; i < n; ++i)
	{
		grid[i].resize(m);
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j];
	}

	cout << maxRegion(grid) << endl;
	return 0;
}
