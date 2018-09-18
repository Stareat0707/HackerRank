#include<algorithm>
#include<map>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string reverseShuffleMerge(string s)
{
	int d[10010];
	int c[26], w[26];

	reverse(s.begin(), s.end());
	int n = s.size();
	for (int i = 0; i < n; ++i) d[i] = s[i] - 'a';
	for (int i = 0; i < n; ++i) c[d[i]]++;
	for (int i = 0; i < 26; ++i) w[i] = c[i] / 2;
	vector<int> ret(n / 2);
	for (int i = 0; 2 * i < n; ++i) {
		for (int c = 0; c < 26; ++c) {
			ret[i] = c;
			int p = 0;
			int l = 0;
			for (int j = 0; j < n; ++j) {
				if (ret[p] == d[j]) {
					++p;
					l = j;
					if (p > i) break;
				}
			}
			if (p <= i) continue;
			int want[26] = {};
			for (int j = 0; j < 26; ++j) want[j] = w[j];
			for (int j = 0; j <= i; ++j) want[ret[j]]--;
			int have[26] = {};
			for (int j = l + 1; j < n; ++j) have[d[j]]++;
			int ok = 1;
			for (int j = 0; j < 26; ++j) if (want[j] < 0 || want[j] > have[j]) ok = 0;
			if (ok) break;
		}
	}
	string r;
	for (int i = 0; 2 * i < n; ++i) r += char(ret[i] + 'a');
	return r;
}

int main()
{
	string s;
	cin >> s;

	cout << reverseshuffleMerge(s) << endl;
	return 0;
}
