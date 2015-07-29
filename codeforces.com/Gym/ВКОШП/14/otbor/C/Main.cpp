/****************************************
**         Solution by NU #2           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "cipher"

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

set <long long> used;

ll my_hash(const vector <int>& v) {
	ll res = 0;

	for (size_t i = 0; i < v.size(); i++) {
		res *= 10;
		res += v[i];
	}

	return res;
}

ostream& operator << (ostream& c, vector <int>& v) {
	for (size_t i = 0; i < v.size(); i++)
		c << v[i] << ' ';
	return c;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int n;

    cin >> n;

    vector <int> a(n);

    for (int i = 0; i < n; i++) {
    	a[i] = i;
    }

    stringstream ans;
    int cnt = 0;

    do {
     	if (used.count(my_hash(a)))
     		continue;

     	vector <int> tmp(a);
     	used.insert(my_hash(a));

     	for (int i = 0; i < n; i++) {
     		cnt++;
     		ans << a[i] + 1 << ' ';
     	}

     	for (int i = 0; i < n - 1; i++) {
     		for (int j = 0; j < n - 1; j++)
     			swap(tmp[j], tmp[j + 1]);

     		used.insert(my_hash(tmp));
     		cnt++;
     		ans << a[i] + 1 << ' ';	
     	}

    } while (next_permutation(all(a)));

    cout << cnt << endl << ans.str() << endl;

	return 0;
}
