#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long triplets(vector<int> a, vector<int> b, vector<int> c)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	a.resize(distance(a.begin(), unique(a.begin(), a.end())));
	b.resize(distance(b.begin(), unique(b.begin(), b.end())));
	c.resize(distance(c.begin(), unique(c.begin(), c.end())));

	long long result = 0;
	long long i = 0, j = 0;
	for (int n : b)
	{
		for (; i < a.size() && a[i] <= n; ++i);

		for (; j < c.size() && c[j] <= n; ++j);

		result += i * j;
	}

	return result;
}

int main()
{
	ifstream fin("input.txt");

	int lena, lenb, lenc;
	fin >> lena >> lenb >> lenc;

	vector<int> a(lena);
	for (int i = 0; i < lena; ++i)
		fin >> a[i];

	vector<int> b(lenb);
	for (int i = 0; i < lenb; ++i)
		fin >> b[i];

	vector<int> c(lenc);
	for (int i = 0; i < lenc; ++i)
		fin >> c[i];

	cout << triplets(a, b, c) << endl;
	return 0;
}
