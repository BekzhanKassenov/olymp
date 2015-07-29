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

	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] != '1' && s[i] != '4') {
			puts("NO");
			return 0;
		}
	}

	if (s[0] == '4') {
		puts("NO");
		return 0;
	}

	int cnt = 0;

	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			cnt = 0;
		else
			cnt++;

		if (cnt > 2) {
			puts("NO");
			return 0;
		}	
	}

	puts("YES");

	return 0;
}
