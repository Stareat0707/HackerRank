#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int formingMagicSquare(vector<vector<int>> s)
{
	vector<vector<vector<int>>> magicSquares(8);
	magicSquares[0] = { { 2, 7, 6 }, { 9, 5, 1 }, { 4, 3, 8 } };
	magicSquares[1] = { { 2, 9, 4 }, { 7, 5, 3 }, { 6, 1, 8 } };
	magicSquares[2] = { { 4, 3, 8 }, { 9, 5, 1 }, { 2, 7, 6 } };
	magicSquares[3] = { { 4, 9, 2 }, { 3, 5, 7 }, { 8, 1, 6 } };
	magicSquares[4] = { { 6, 1, 8 }, { 7, 5, 3 }, { 2, 9, 4 } };
	magicSquares[5] = { { 6, 7, 2 }, { 1, 5, 9 }, { 8, 3, 4 } };
	magicSquares[6] = { { 8, 1, 6 }, { 3, 5, 7 }, { 4, 9, 2 } };
	magicSquares[7] = { { 8, 3, 4 }, { 1, 5, 9 }, { 6, 7, 2 } };

	int result = 40;
	for (int k = 0; k < 8; ++k)
	{
		int difference = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (magicSquares[k][i][j] != s[i][j])
					difference += abs(magicSquares[k][i][j] - s[i][j]);
			}
		}

		result = min(result, difference);
	}

	return result;
}

int main()
{
	vector<vector<int>> s(3);
	for (int i = 0; i < 3; ++i)
	{
		s[i].resize(3);
		for (int j = 0; j < 3; ++j)
			cin >> s[i][j];
	}

	cout << formingMagicSquare(s) << endl;
	return 0;
}
