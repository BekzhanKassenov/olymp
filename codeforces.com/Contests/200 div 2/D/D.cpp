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

	string s;

	getline(cin, s);

	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '-')
			cnt1++;
		else
			cnt2++;	
	}

	if ((cnt1 & 1) || (cnt2 & 1))
		cout << "No";
	else
		cout << "Yes";	

	return 0;
}
