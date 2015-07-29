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
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

string X;
int k, D, p[MAXN], r;
char c[MAXN];
bool used[MAXN], d[10];

void print(int ver) {
	if (ver == r)
		return;
	print(p[ver]);
	X.append(1, c[ver]);
}

bool check() {
        int rr = 0;
    for (size_t i = 0; i < X.length(); i++) {
    	rr *= 10;
    	rr += X[i] - '0';
    	rr %= k;
    }
    return rr == 0;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    cin >> X >> k >> D;
    for (int i = 0; i < D; i++) {
    	int x;
    	cin >> x;
    	d[x] = true;
    }
    for (size_t i = 0; i < X.length(); i++) {
    	r *= 10;
    	r += X[i] - '0';
    	r %= k;
    }
    if (r == 0) {
        cout << X;
    	return 0;
    }

    queue<int> q;
    q.push(r);
    p[r] = -INF;
    
    while (!q.empty()) {
    	int t = q.front();
    	q.pop();
    	used[t] = true;
    	if (t == 0) {
    		print(t);
    		cout << X;
    		assert(check());
    		return 0;
    	}
    	for (int i = 0; i < 10; i++) {
    		int tp = (t*10+i)%k;
    		if (d[i] && !used[tp]) {
    			used[tp] = true;
    			p[tp] = t;
    			c[tp] = '0' + i;
    			q.push(tp);
    		}
    	}
    	
    }
    cout << "-1";
    return 0;
}
