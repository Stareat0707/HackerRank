#define toStr(x) #x
#define io(v) cin >> v
#define FUNCTION(a, b) void a(int& m, int vi) { if (vi b m) m = vi; }
#define INF 2147483647
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)

#include <iostream>
#include <vector>

using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, < )
FUNCTION(maximum, > )

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	foreach(v, i)
		io(v)[i];

	int mn = INF;
	int mx = -INF;
	foreach(v, i)
	{
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}

	cout << toStr(Result = ) << ' ' << mx - mn;
	return 0;
}
