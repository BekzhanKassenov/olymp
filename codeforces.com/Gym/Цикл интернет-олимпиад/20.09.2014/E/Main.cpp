/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "kings"

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

pair <int, string> a[3];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d%d", &a[0].first, &a[1].first, &a[2].first);
    int x;

    for (int i = 0; i < 3; i++) {
     	scanf("%d", &x);
     	a[i].first *= x;
    }

    a[0].second = "Joffrey";
    a[1].second = "Robb";
    a[2].second = "Stannis";

    sort(a, a + 3);

    vector <string> ans;
    for (int i = 0; i < 3; i++) {
     	if (a[i].first == a[2].first)
     		ans.push_back(a[i].second);
    }

    sort(all(ans));

    for (size_t i = 0; i < ans.size(); i++)
    	cout << ans[i] << ' ';

    return 0;
}
