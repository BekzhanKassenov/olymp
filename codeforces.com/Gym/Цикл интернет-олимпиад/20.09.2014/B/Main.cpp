/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "basketball"

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

int n, a, b;
int x, y;
char temp[50];
map <string, int> Map;
int ans;
string ansstr;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
		gets(temp);
		Map[string(temp)] = 0;
    }

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
     	scanf("%d:%d %s", &a, &b, temp);
     	int diff = abs(a - x) + abs(b - y);
		Map[string(temp)] += diff;
		x = a;
		y = b;

		if (Map[string(temp)] > ans) {
		 	ans = Map[string(temp)];
		 	ansstr = string(temp);
		}
    }

    cout << ansstr << ' ' << ans << endl;

    return 0;
}
