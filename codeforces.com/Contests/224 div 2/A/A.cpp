/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
    string s;

    cin >> s;

    int cnt[2] = {};

    int pos = 0;

    for (size_t i = 0; i < s.size(); i++) {
    	if (s[i] == '|')
    		pos++;
    	else
    		cnt[pos]++;
    }

    string t;

    cin >> t;

    pos = 0;

    int len = t.size();

    while (pos < len) {
    	if (cnt[0] < cnt[1]) {
    		cnt[0]++;
    		s = t[pos] + s;
    	} else {
    		cnt[1]++;
    		s = s + t[pos];
    	}

    	pos++;
    }

    if (cnt[0] != cnt[1]) {
    	cout << "Impossible";
    } else
    	cout << s;

	return 0;
}

