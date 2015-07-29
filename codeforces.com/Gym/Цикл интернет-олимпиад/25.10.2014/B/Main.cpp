/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "string"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
string s, temp;
set <pair <string, int> > Set;

int main() {
	ios_base :: sync_with_stdio(false);
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n >> m;
    cin >> s;

    for (int i = 0; i < m; i++) {
    	cin >> temp;
    	Set.insert(make_pair(temp, i));
    }

    for (int i = 0; i < n; i += n / m) {
     	temp = s.substr(i, n / m);

     	set <pair <string, int> > :: iterator it = Set.lower_bound(make_pair(temp, -1));
     	
     	cout << it -> second + 1 << ' ';
     	
     	Set.erase(it);
    }

    cout << endl;

    return 0;
}
