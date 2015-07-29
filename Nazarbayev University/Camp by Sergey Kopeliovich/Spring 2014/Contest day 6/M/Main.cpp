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
#define File "pingpong"

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
#define MN 30
double prob[MN][MN], p, p1, p2;
bool used[MN][MN];
#define N 28
void bfs(int a, int b){
//cout << a << " " << b << endl;
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    while (!q.empty()){
        a = q.front().F;
        b = q.front().S;
        q.pop();
        if (a < N && b < N && !used[a][b]){
            if (abs(a-b) >= 2 && max(a, b) >= 11)
                continue;
            used[a][b] = 1;
            prob[a+1][b] += prob[a][b]*p;
            prob[a][b+1] += prob[a][b]*(1.0 - p);
            q.push(MP(a+1, b));
            q.push(MP(a, b+1));
        }
    }
}
double find_(int a, int b){
    double ans = 0.0;
    for (int i = a; i < N; ++i){
        for (int j = b; j < N; ++j){
            if (i-j >= 2 && i >= 11)            
                ans += prob[i][j];       
        }
    }
    return ans;
}
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2 >> p;
    prob[a1][b1] = 1.0;
    bfs(a1, b1);
    p1 = find_(a1, b1);

    for (int i = 0; i < MN; i++){ for (int j = 0; j < MN; j++){ prob[i][j] = 0.0; used[i][j] = 0; }}
    prob[a2][b2] = 1.0;
    bfs(a2, b2);
    p2 = find_(a2, b2);
    if (p2-p1 > 0.0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
