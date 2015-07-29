/****************************************
**     Solution by Bekzhan Kassenov    **
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

ll sqr(int n) {
    return 1ll * n * n;
}

struct Point {
    int x, y, z;

    Point() { }

    Point(const vector <int>& a) : x(a[0]), y(a[1]), z(a[2]) { }

    Point(int x, int y, int z) : x(x), y(y), z(z) { }

    Point operator + (const Point& p) const {
        return Point(x + p.x, y + p.y, z + p.z);
    }

    Point operator - (const Point& p) const {
        return Point(x - p.x, y - p.y, z - p.z);
    }

    bool operator == (const vector <int>& p) const {
        vector <int> temp(3);
        temp[0] = x, temp[1] = y, temp[2] = z;
        sort(all(temp));

        return p == temp;
    }

    bool operator < (const Point& p) const {
        if (x != p.x)
            return x < p.x;

        if (y != p.y)
            return y < p.y;

        return z < p.z;
    }

    bool operator != (const Point& p) const {
        return *this < p || p < *this;
    }

    ll sqrlen() const {
        return sqr(x) + sqr(y) + sqr(z);
    }

    ll operator ^ (const Point& p) const {
        return 1ll * x * p.x + 1ll * y * p.y + 1ll * z * p.z;
    }
};

ostream& operator << (ostream& c, const Point& p) {
    c << p.x << ' ' << p.y << ' ' << p.z;
    return c;
}

vector <int> a[8];
int p[4];
bool taken[8];
int cnt[8];

bool check_point(const Point& a, const Point& b, const Point& c) {
    ll lena = a.sqrlen();
    ll lenb = b.sqrlen();
    ll lenc = c.sqrlen();

    if (lena == 0 || lenb == 0 || lenc == 0)
        return false;

    if (lena != lenb || lenb != lenc || lenc != lena)
        return false;

    if (!(a != b && b != c && a != b))
        return false;

    return (a ^ b) == 0 && (a ^ c) == 0 && (b ^ c) == 0;
}

void check() {
    Point ans[8];

    Point A(a[p[0]]);
    Point B(a[p[1]]);
    Point C(a[p[2]]);
    Point D(a[p[3]]);

    ans[p[0]] = A;
    ans[p[1]] = B;
    ans[p[2]] = C;
    ans[p[3]] = D;

    Point v1(B - A);
    Point v2(C - A);
    Point v3(D - A);

    //cout << A << ' ' << B << ' ' << C << ' ' << D << endl;

    if (!check_point(v1, v2, v3))
        return;

    multiset <Point> st;
    st.insert(Point(A + v1 + v2));
    st.insert(Point(A + v1 + v3));
    st.insert(Point(A + v3 + v2));
    st.insert(Point(A + v1 + v2 + v3));

    for (int i = 0; i < 8; i++) {
        if (taken[i])
            continue;

        for (set <Point> :: iterator it = st.begin(); it != st.end(); it++) {
            if (*it == a[i]) {
                ans[i] = *it;
                st.erase(it);
                break;
            }
        }
    }

    if (st.empty()) {
        puts("YES");

        for (int i = 0; i < 8; i++) {
            cout << ans[i] << endl;
        }

        exit(0);
    }
}

void go(int pos) {
    if (pos == 4) {
        check();
        return;
    }
    
    //int i = 0;
    //if (pos)
     //   i = p[pos - 1] + 1;

    for (int i = 0; i < 8; i++) {
        bool flag = true;
        for (int j = 0; j < pos && flag; j++) {
            if (i == p[j])
                flag = false;
        }

        if (!flag)
            continue;
        
        p[pos] = i;
        taken[i] = true;
        
        do {
            go(pos + 1);
        } while (next_permutation(all(a[i])));
        taken[i] = false;

        sort(all(a[i]));
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 8; i++) {
        a[i].resize(3);

        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }

        sort(all(a[i]));
    }

    go(0);

    puts("NO");

    return 0;
}
