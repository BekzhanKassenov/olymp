/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "longpath"

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
const int maxn = 100010;

double curT;

struct group {
    int cnt;
    double x;
    
    group() { }
    
    group(int cnt, double x) : cnt(cnt), x(x) { }
    
    bool operator < (const group& gr) const {
        return x < gr.x;
    }
};

ostream& operator << (ostream& c, const group& gr) {
    c << '(' << gr.cnt << ", " << gr.x << ')';
    return c;
}

struct collision {
    group gr1, gr2;
    
    double t, x;
    
    collision() { }
    
    collision(const group& gr1, const group& gr2) : gr1(gr1), gr2(gr2) {
        double v1 = 100.0 / gr1.cnt;
        double v2 = 100.0 / gr2.cnt;
        
        if (v2 >= v1) {
            t = INF;
            x = INF;
        } else {
            if (gr1.x == gr2.x)
                t = 0, x = gr1.x;
            else {
                t = (gr1.x - gr2.x) / (v2 - v1);
                x = gr1.x + v1 * t;
            }
        }
        
        if (t != INF)
            t += curT;
    }
    
    bool operator < (const collision& col) const {
        if (t != col.t)
            return t < col.t;
            
        if (gr1 < col.gr1 || col.gr1 < gr1)
            return gr1 < col.gr1;
            
        return gr2 < col.gr2;
    }
};

multiset <collision> st;
map <group, group> prevasd, nextasd;
int n, m;
group g[maxn];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%lf", &g[i].cnt, &g[i].x);
    }
    
    sort(g, g + n);
    
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            prevasd[g[i]] = g[i - 1];
        }
        
        if (i < n - 1) {
            nextasd[g[i]] = g[i + 1];
            
            st.insert(collision(g[i], g[i + 1]));
        }
    }
    
    while (!st.empty()) {
        collision cur = *st.begin();
        
        /*for (set <collision> :: iterator it = st.begin(); it != st.end(); it++) {
            cerr << it -> t << ' ' << it -> x << endl;
        }
        
        cerr << endl;
        */
        
        if (cur.t == INF)
            break;
            
        curT = cur.t;
            
        st.erase(st.begin());
        
        group prv(-1, -1), nxt(-1, -1);
        
        group ngr(cur.gr1.cnt + cur.gr2.cnt, cur.x);
        
//        cerr << cur.gr1 << '+' << cur.gr2 << "--->" << ngr << endl;
        
        if (prevasd.count(cur.gr1)) {
            prv = prevasd[cur.gr1];
            st.erase(st.find(collision(prv, cur.gr1)));
//            cerr << prv << ' ' << cur.gr1 << endl;
            prevasd.erase(cur.gr1); 
            nextasd[prv] = ngr;
            prevasd[ngr] = prv;
            st.insert(collision(prv, ngr));
        }
        
        if (nextasd.count(cur.gr2)) {
            nxt = nextasd[cur.gr2];
            st.erase(st.find(collision(cur.gr2, nxt)));
            nextasd.erase(cur.gr2);
            nextasd[ngr] = nxt;
            prevasd[nxt] = ngr;
            st.insert(collision(ngr, nxt));
        }
        
        prevasd.erase(cur.gr2);
        nextasd.erase(cur.gr1);
    }
    
    set <group> Set;
    
    for (set <collision> :: iterator it = st.begin(); it != st.end(); it++) {
        Set.insert(it -> gr1);
        Set.insert(it -> gr2);
    }
    
    cout << Set.size() << endl;
    
    for (set <group> :: iterator it = Set.begin(); it != Set.end(); it++) {
        printf("%d ", it -> cnt);
    }
    
    return 0;
}
