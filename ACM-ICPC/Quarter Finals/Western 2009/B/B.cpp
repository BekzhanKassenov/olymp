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
	string s, t;

	getline(cin, s);
	getline(cin, t);

	int cnt = 0;

	for (int i = 0; i < 4; i++)
		cnt += (s[i] == t[i]);

    int ans = 0;

	for (int i = 0; i < 4; i++) {
    	for (int j = 0; j < 4; j++) {
    		if (s[i] == t[j] && i != j)
    			ans++;
    	}	
    }

    cout << cnt << ' ' << ans;
	return 0;
}
