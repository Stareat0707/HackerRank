#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct Location
{
	int x, y, count;
};

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
	int temp = startX;
	startX = startY;
	startY = temp;

	temp = goalX;
	goalX = goalY;
	goalY = temp;

	vector<vector<bool>> visit(grid.size());
	for (int i = 0; i < grid.size(); ++i)
		visit[i].resize(grid.size());

	queue<Location> q;
	q.push({ startX, startY, 0 });

	while (!q.empty())
	{
		Location front = q.front();
		q.pop();

		if (visit[front.x][front.y])
			continue;
		else
			visit[front.x][front.y] = true;

		if (front.x == goalX && front.y == goalY)
			return front.count;

		for (int x = front.x; x < grid.size() && grid[front.y][x] != 'X'; ++x)
			q.push({ x, front.y, front.count + 1 });

		for (int x = front.x; x >= 0 && grid[front.y][x] != 'X'; --x)
			q.push({ x, front.y, front.count + 1 });

		for (int y = front.y; y < grid.size() && grid[y][front.x] != 'X'; ++y)
			q.push({ front.x, y, front.count + 1 });

		for (int y = front.y; y >= 0 && grid[y][front.x] != 'X'; --y)
			q.push({ front.x, y, front.count + 1 });
	}

	return 0;
}

int main()
{
	int n;
	cin >> n;

	vector<string> grid(n);
	for (int i = 0; i < n; ++i)
		cin >> grid[i];

	int startX, startY, goalX, goalY;
	cin >> startX >> startY >> goalX >> goalY;

	cout << minimumMoves(grid, startX, startY, goalX, goalY) << endl;
	return 0;
}
