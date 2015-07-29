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

int n, x, k, a, ans;

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d%d", &n, &x, &k);

	priority_queue <int> q;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		q.push(a);
	}

	long long ans = 0;

	while (!q.empty()) {
		//cout << q.size() << endl;
		int cur = q.top();
		q.pop();

		if (cur >= x + k) {
			ans += cur / (x + k);
			cur %= x + k;
			if (cur != 0)
				q.push(cur);
		} else {
			ans++;
			
			int t = k;

			if (cur >= x) 
			    t = k - (cur - x);

			while (t > 0 && !q.empty()) {
			    cur = q.top();
			    q.pop();

			    if (cur <= t)
			    	t -= cur;
			    else {
			    	cur -= t;
			    	t = 0;
			    	
			    	if (cur != 0)
			    		q.push(cur);
			    }
			}
		}
	}

	cout << ans;

	return 0;
}
