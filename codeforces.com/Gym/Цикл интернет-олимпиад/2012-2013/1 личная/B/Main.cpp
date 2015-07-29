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
#define File "points"

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
const int maxn = 2020;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, maxy, child[maxn][maxn];

struct st {
    int x, y;
    int num;
    
    void read() {
        scanf("%d%d", &x, &y);
    }
    
    bool operator < (const st& s) const {
        return x < s.x;
    }
};

st a[maxn];
bool used[maxn];
map <int, int> Map;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        a[i].read();
        a[i].num = i + 1;    
    
        if (a[i].y & (a[i].y - 1)) {
            puts("NO");
            printf("%d", i + 1);
            return 0;
        }
        
        maxy = max(a[i].y, maxy);
    }   
    
    for (int i = 0; i < n; i++) {
        int diff = maxy / a[i].y;
        a[i].x *= diff;
        a[i].y *= diff;
    }
    
    sort(a, a + n);
    
    for (int i = 0; i < n; i++)
        Map[a[i].x] = i;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int mid = (a[i].x + a[j].x) >> 1;

            if (((a[i].x + a[j].x) & 1) || i == j || !Map.count(mid))
                child[i][j] = -1;
            else {
                child[i][j] = Map[mid];        
                used[Map[mid]] = true;
            }
        }
    }
    
    for (int i = 1; i < n - 1; i++) {
        if (!used[i]) {
            puts("NO");
            printf("%d", a[i].num);
            return 0;
        }
    }
    
    set <PII> Set;
    Set.insert(MP(0, n - 1));
    memset(used, false, sizeof used);
    
    used[0] = used[n - 1] = true;
    
    puts("YES");
    
    for (int i = 0; i < n - 2; ) {
        PII cur = *Set.begin();
        Set.erase(Set.begin());

        int ch = child[cur.F][cur.S];
        
        if (used[ch])
            continue;
        
        i++;
        printf("%d %d %d\n", a[ch].num, a[cur.F].num, a[cur.S].num);
        
        used[ch] = true;
        
        for (int j = 0; j < n; j++) {
            if (used[j] && child[ch][j] != -1 && !used[child[ch][j]]) {
                Set.insert(MP(min(ch, j), max(ch, j)));
            }
        }
    }
    
    return 0;
}
