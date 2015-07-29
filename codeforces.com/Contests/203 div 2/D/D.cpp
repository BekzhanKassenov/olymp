/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

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

ll gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

struct Point {
    ll x, y;

    Point() {}
    
    Point(int x, int y): x(x), y(y) {}

    Point(const Point& a) {
    	*this = a;
    }

    Point operator - (const Point& a) const {
        return Point(x - a.x, y - a.y);
    }

    inline ll dist() {
        return sqr(x) + sqr(y);
    }

    bool operator < (const Point& p1) const {
    	return (x < p1.x || (x == p1.x && y < p1.y));
    }
};

struct Line {
    ll a, b, c;

    Line() {}

    inline void normalize() {
        if (a < 0 || (a == 0 && b < 0)) {
            a *= -1;
            b *= -1;
            c *= -1;
        }

        ll g = gcd(gcd(abs(a), abs(b)), abs(c));

        if (g > 1) {
            a /= g;
            b /= g;
            c /= g;
        }
    }

    Line(int aa, int bb, int cc) {
        a = aa, b = bb, c = cc;
        normalize();    
    }

    Line(const Point& p1, const Point& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p1.y * p2.x - p1.x * p2.y;

        normalize();
    }
};

const int maxn = 300010;

vector <pair <Point, int> > v[maxn];
vector <int> vec[maxn];
map <ll, int> position;
vector <Point> tmp[maxn];

Point center[2000];
ll rad[2000];

ll get_hash(const Line& l) {
	ll a = l.a + 50000;
	ll b = l.b + 50000;
	ll c = l.c + 2000000000;
	ll ret = c * 2000000000LL;
	ret += a * 100000;
	ret += b;
	return ret;
}

void prepare(int pos) {
	vector <pair <Point, int> >& cur = v[pos];
    sort(all(cur));
    
    vec[pos].resize(cur.size());

    int cnt = 0;

    for (size_t i = 0; i < cur.size(); i++) {
        if (cur[i].S == 0)
            cnt++;
        else
            cnt--;  

        vec[pos][i] = cnt;
    }
}

ll get_ans(const Point& p1, const Point& p2) {
	Line cur(p1, p2);
    Point mid((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    Point norm(cur.a, cur.b);
    norm.x += mid.x;
    norm.y += mid.y;

    cur = Line(mid, norm);

    ll h = get_hash(cur);

	if (!position.count(h))
		return 0;

	int pos = position[h];

	int q = upper_bound(all(v[pos]), MP(mid, 1)) - v[pos].begin() - 1;

	if (q != -1)
		return vec[pos][q];	

    return 0;
}                            

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int n, m;

    scanf("%d%d", &n, &m);

    Point p1, p2;

    int sz = 0;

    for (int i = 0; i < n; i++) {
    	scanf("%I64d%I64d%I64d%I64d", &p1.x, &p1.y, &p2.x, &p2.y);
        p1.x *= 2, p1.y *= 2;
        p2.x *= 2, p2.y *= 2;
        Line cur(p1, p2);
        ll h = get_hash(cur);

        int pos = 0;

        if (position.count(h))
        	pos = position[h];
        else {
        	pos = sz++;
        	position[h] = pos;
    	}	

        v[pos].push_back(MP(p1, (p1 < p2) ? 0 : 2));
        v[pos].push_back(MP(p2, (p1 < p2) ? 2 : 0));
    }

    for (int i = 0; i < sz; i++)
    	prepare(i);

    ll ans = 0;

    for (int i = 0; i < m; i++) {
    	scanf("%I64d%I64d%I64d", &center[i].x, &center[i].y, &rad[i]);
        center[i].x *= 2;
        center[i].y *= 2;
        rad[i] *= 2;

        for (size_t j = 0; j < tmp[rad[i]].size(); j++) {        
            if ((center[i] - tmp[rad[i]][j]).dist() > 4 * sqr(rad[i]))
            	ans += get_ans(center[i], tmp[rad[i]][j]);
        }
        tmp[rad[i]].push_back(center[i]);
    }
                                     
    printf("%I64d", ans);
    return 0;
}