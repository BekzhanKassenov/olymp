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

const int maxn = 60;

int a[maxn][maxn];
int n, m, k;

void place(int num) {
    int resi = maxn, resj = maxn;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && resi + resj > i + j) {
                resi = i;
                resj = j;
            }
        }
    }
    
    a[resi][resj] = num;
}

bool cmp(const PII& a, const PII& b) {
    return (a.F + a.S > b.F + b.S);
}

int dx[4] = {1, 0};
int dy[4] = {0, 1};

bool ok(int aa, int bb) {
    return (aa >= 0 && aa < n && bb >= 0 && bb < m && a[aa][bb] == 0);
}

vector <string> st;
stringstream ss;

char temp[100];

void bfs(int si, int sj) {
    queue <PII> q;
    q.push(MP(0, 0));
    
    vector <vector <bool> > used(n, vector <bool> (m));
    
    used[0][0] = true;
    
    vector <vector <PII> > pr(n, vector <PII> (m));
    
    while (!q.empty()) {
        int x = q.front().F;
        int y = q.front().S;
        
        if (x == si && y == sj) {
            break;
        }
        
        q.pop();
        
        for (int i = 0; i < 2; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            if (ok(tx, ty) && !used[tx][ty]) {
                used[tx][ty] = true;
                q.push(MP(tx, ty));    
                pr[tx][ty] = MP(x, y);
            }
            
        }
    }
    
    
    vector <PII> path;
    path.push_back(MP(si, sj));
    
    PII cur = MP(si, sj);
    
    while (cur != MP(0, 0)) {
        path.push_back(pr[cur.F][cur.S]);
        cur = pr[cur.F][cur.S];
    }
    
    reverse(all(path));
    
    for (size_t i = 0; i < path.size(); i++)
        ss << '(' << path[i].F + 1 << ',' << path[i].S + 1 << ") ";
        
    ss << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        place(k);
    }
    
    vector <PII> vec;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                vec.push_back(MP(i, j));
            }
        }
    }
    
    memset(a, 0, sizeof a);
    
    sort(all(vec), cmp);
    
    int ans = 0;
    
    for (int i = 0; i < k; i++) {
        bfs(vec[i].F, vec[i].S);
        ans += vec[i].F + vec[i].S + 1;
    }
    
    cout << ans << endl << ss.str();
    
    return 0;
}
