/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <int > prefix_function (const string &s) {
    int n = s.length();
	vector <int > p (n);
	p[0] = 0;

	for (int i = 1; i < n; i++) {
		int j = p[i - 1];

		while (s[j] != s[i] && j > 0) 
			j = p[j - 1];
		
		if (s[i] == s[j])
			j++;

		p[i] = j;
	}

	return p;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    string s;

    cin >> s;

    vector <int > v = prefix_function (s);
	    
	if (s.length() % (s.length() - v.back()) != 0)
		cout << s.length();
	else
		cout << s.length() - v.back();

    return 0;
}
