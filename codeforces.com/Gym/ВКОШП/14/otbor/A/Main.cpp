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
#define File "bank"

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

const int maxn = 100010;

struct str {
 	char type1, type2;
 	ll _time, num;

 	str() { }

 	str(char type1, char type2, ll _time, ll num) : type1(type1), type2(type2), _time(_time), num(num) { }
	
	bool operator < (const str& p) const {
		if (_time != p._time)
			return _time < p._time;

		if (type1 != p.type1)
			return type1 == 'f';

		return num < p.num;
	}
};

ll t[maxn], a[maxn], b[maxn], ans[maxn], buh_free;
int n, m;
queue <int> q_work, q_buh;
set <str> q;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
    	scanf("%I64d%I64d%I64d", &t[i], &a[i], &b[i]);
    	q.insert(str('c', 'w', t[i], i));
    }

    buh_free = 1;

    while (!q.empty()) {
    	str cur = *q.begin();
    	q.erase(q.begin());

    	if (cur.type1 == 'c') {
    		if (cur.type2 == 'w') {
    			if (m > 0) {
    				q.insert(str('f', 'w', cur._time + a[cur.num], cur.num));
    				m--;
    			} else 
    				q_work.push(cur.num);
    		} else {
    			if (buh_free) {
    				buh_free = false;
    				q.insert(str('f', 'b', cur._time + b[cur.num], cur.num));
    			} else 
    				q_buh.push(cur.num);
    		}
    	} else {
    		if (cur.type2 == 'w') {
    			q.insert(str('c', 'b', cur._time, cur.num));

    			if (!q_work.empty()) {
    				q.insert(str('f', 'w', cur._time + a[q_work.front()], q_work.front()));
    				q_work.pop();
    			} else 
    				m++;
    		} else {
    			ans[cur.num] = cur._time;

    			if (!q_buh.empty()) {
    				q.insert(str('f', 'b', cur._time + b[q_buh.front()], q_buh.front()));
    				q_buh.pop();
    			} else 
    				buh_free = true;
    		}
    	}
    }

    for (int i = 0; i < n; i++)
    	cout << ans[i] << endl;

	return 0;
}
