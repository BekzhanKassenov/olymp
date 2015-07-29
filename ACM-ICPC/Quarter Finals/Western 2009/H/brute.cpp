/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	vector <set <string > > s;
	set <string >::iterator it;

	string t;
	bool ok;
	int id, num[100];
	long long g = 0, clone;

	for (int i = 0; i < 20; i++) num[i] = 0;

	while (g < 1000000000) {
		ok = false, clone = g, t = "", id = 0;

		while (clone) {
		    t += char ((clone % 10) + 48);
			id++;
			clone /= 10;
		}
		reverse (t.begin(), t.end());

		for (int i = 0; i < id - 1; i++)
			if (t[i] == '1' && t[i + 1] == '3')
			{
				ok = true;
				break;
			}

		if (ok)
			num[id]++;

		g++;
	}

	for (int i = 3; i < 10; i++)
		cout << i << " " << num[i] << " -- div " << num[i] / num[i - 1]<< "  -- diff " << num[i] - num[i - 1] << endl;

	return 0;
}
