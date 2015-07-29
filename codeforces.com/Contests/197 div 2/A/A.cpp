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

	int c[3] = {0};

	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] != '+')
			c[s[i] - '1']++;

	VI a;

	for (int i = 0; i < c[0]; i++)
		a.push_back(1);

	for (int i = 0; i < c[1]; i++)
		a.push_back(2);

	for (int i = 0; i < c[2]; i++)
		a.push_back(3);

	for (int i = 0; i < (int)a.size(); i++) {
	 	cout << a[i];

	 	if (i == (int)a.size() - 1)
	 		cout << endl;
	 	else
	 		cout << '+';	
	}	

	return 0;
}
