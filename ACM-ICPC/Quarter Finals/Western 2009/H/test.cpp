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

bool check(int n) {
	string s;

	while (n) {
		s += n % 10 + '0';
		n /= 10;
	}

	for (int i = 1; i < (int)s.size(); i++)
		if (s[i] == '1' && s[i - 1] == '3')
			return false;

	return true;	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	for (int i = 1; ; i++) {
	    if (check(i))
	    	n--;
		
		if (!n) {
			cout << i;
			break;
		}
			
	}

	return 0;
}
