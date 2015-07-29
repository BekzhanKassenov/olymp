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

int a[1010][1010], n, m;
bool big[1010][1010];
vector <int> pos;

bool check(int val) {
	memset(big, 0, sizeof big);

	for (int i = 0; i < n; i++) {
		pos.clear();
		for (int j = 0; j < m; j++)
			if (a[i][j] >= val)
				pos.push_back(j);

		for (vector <int> :: iterator it = pos.begin(); it != pos.end(); it++) {
			for (vector <int> :: iterator jt = pos.begin(); jt != pos.end(); jt++) {
				if (it == jt)
					continue;

				if (big[*it][*jt])
					return true;
				else
					big[*it][*jt] = true;
			}
		}
	}

	return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
    		scanf("%d", &a[i][j]);

    int l = -1, r = (int)1e9 + 1;

    while (r - l > 1) {
    	int mid = (r + l) >> 1;

    	if (check(mid))
    		l = mid;
    	else
    		r = mid;	
    }

    cout << l;

    return 0;
}