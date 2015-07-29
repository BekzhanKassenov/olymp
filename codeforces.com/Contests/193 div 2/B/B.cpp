/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
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
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}


const int maxn = 1000010;
int n, k, a[maxn];
pair <ll, int> ans[maxn];
ll cur;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = n - 1; i > n - k; i--) {
		cur += a[i];
		ans[i] = MP(-1, n);
   	}

   	for (int i = n - k; i >= 0; i--) {
   		cur -= a[i + k];
   		cur += a[i];

   		if (cur >= ans[i + 1].F)
   			ans[i] = MP(cur, i);
   		else
   			ans[i] = ans[i + 1];
   	}

   	//for (int i = 0; i < n; i++)
   	//	cout << ans[i].F << ' ' << ans[i].S << endl;

   	cur = 0;
	
	for (int i = 0; i < k; i++)
		cur += a[i];

	ll anss = cur + ans[k].F;
	pair <int, int> aa = MP(0, ans[k].S);

	for (int i = k; i < n; i++) {
		cur -= a[i - k];
		cur += a[i];

		if (ans[i + 1].F != -1) {
			if (anss < ans[i + 1].F + cur) {
				anss = ans[i + 1].F + cur;
				aa = MP(i - k + 1, ans[i + 1].S);
			}
		} else
			break;
	}

	cout << aa.F + 1 << ' ' << aa.S + 1;

	return 0;
}
