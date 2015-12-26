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
const int MOD = 1000 * 1000 * 1000;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char type;
int x, l, r;
bool prev_query = false;
long long prev_ans;
set <int> Set;

long long sum(int l, int r) {
    set <int>::const_iterator first = Set.upper_bound(l - 1);
    set <int>::const_iterator last = Set.lower_bound(r);

   // cerr << endl;
    long long result = 0;
    for (set <int>::const_iterator it = Set.begin(); it != Set.end(); it++) {
        if (l <= *it && *it <= r) {
        	result += *it;
        	//cerr << *it << ' ';
		}
    }
    //cerr << endl;

    return result;
}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("stup.out", "w", stdout);
#endif

    scanf("%d\n", &n);

    while (n--) {
    	scanf("%c ", &type);
    	if (type == '?') {
    		scanf("%d %d\n", &l, &r);
    		prev_ans = sum(l, r);
    		prev_query = true;
    		printf("%I64d\n", prev_ans);
    	} else {
    		scanf("%d\n", &x);

    		if (prev_query) {
    			x = (x + prev_ans) % MOD;
    		}

    		prev_query = false;
    		Set.insert(x);
    	}
    }

    return 0;
}
    	