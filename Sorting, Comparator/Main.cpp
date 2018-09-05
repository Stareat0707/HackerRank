#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Player
{
	string name;
	int score;
};

class Checker
{
public:
	static int comparator(Player a, Player b)
	{
		if (a.score < b.score)
			return -1;
		else if (a.score > b.score)
			return 1;
		else if (a.name > b.name)
			return -1;
		else if (a.name < b.name)
			return 1;
		else
			return 0;
	}
};

bool compare(Player a, Player b)
{
	if (Checker::comparator(a, b) == -1)
		return false;

	return true;
}

int main()
{
	int n;
	cin >> n;

	vector<Player> players(n);
	for (int i = 0; i < n; ++i)
	{
		string name;
		int score;
		cin >> name >> score;

		players.push_back({ name, score });
	}

	sort(players.begin(), players.end(), compare);

	for (auto& player : players)
		cout << player.name << ' ' << player.score << endl;

	return 0;
}
