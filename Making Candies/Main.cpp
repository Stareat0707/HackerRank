#include <iostream>

using namespace std;

bool check(long long m, long long w, long long p, long long n, long long rounds)
{
	if (m >= (n + w - 1) / w)
		return true;

	long long cur = m * w;

	if (--rounds == 0)
		return false;

	while (true)
	{
		long long rem = n - cur;
		long long rnds = (rem + m * w - 1) / (m * w);

		if (rnds <= rounds)
			return true;

		if (cur < p)
		{
			rem = p - cur;
			rnds = (rem + m * w - 1) / (m * w);
			rounds -= rnds;

			if (rounds < 1)
				return false;

			cur += rnds * m * w;
		}

		cur -= p;
		m <= w ? ++m : ++w;
	}

	return false;
}

long long minimumPasses(long long m, long long w, long long p, long long n)
{
	long long low = 1, high = 1000000000000;

	while (low < high)
	{
		long long mid = (low + high) >> 1;
		if (check(m, w, p, n, mid))
			high = mid;
		else
			low = mid + 1;
	}

	return low;
}

int main()
{
	long long m, w, p, n;
	cin >> m >> w >> p >> n;

	cout << minimumPasses(m, w, p, n) << endl;
	return 0;
}
