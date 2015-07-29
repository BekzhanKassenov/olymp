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
#define File "polyline"

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
const int maxn = 50010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector<pair<int, int> > ans;
pair<int, int> cur_pos;
void push3(){
    pair<int, int> tp = cur_pos;
    tp.S += 3;
    ans.push_back(tp);
    tp.S -= 3;
    tp.F += 3;
    ans.push_back(tp);
    ans.push_back(cur_pos);
    tp.S += 3;
    ans.push_back(tp);           
}
void push4(){
    pair<int, int> tp = cur_pos;
    tp.S += 3;
    ans.push_back(tp);
    tp.F += 3;
    ans.push_back(tp);
    tp.S -= 4;
    ans.push_back(tp);
    tp = cur_pos;
    tp.S += 2;
    ans.push_back(tp);
    tp.F += 3;
    ans.push_back(tp);
    tp.S -= 2;
    tp.F -= 2;
    ans.push_back(tp);
}
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    int n, nn;
    scanf("%d", &n);
    nn = n;
    cur_pos.F = cur_pos.S = 0;
    bool was = 0;
    if (n == 3){
        ans.push_back(MP(0, 0));
        ans.push_back(MP(2, 2));
        ans.push_back(MP(-1, 2));
        ans.push_back(MP(2, 1));
        ans.push_back(MP(2, 2));                        
    }
    else if (n == 4){
        ans.push_back(cur_pos);
        push4();                                
    }
    else {
        was = 1;
        ans.push_back(cur_pos);
    }
    while (n > 4){
        pair<int, int> tp = cur_pos;
        tp.S += n-1;
        ans.push_back(tp);
        tp.F += n-1;
        ans.push_back(tp);
        tp.S -= n-1;
        ans.push_back(tp);
        tp.F = cur_pos.F + 1;
        ans.push_back(tp);
        n -= 2;
        cur_pos.F++;
        cur_pos.S++;                                                                                       
    }
    if (was && n == 3){
        push3();
    }
    if (was && n == 4){
        push4();
    }
    assert(ans.size() - 1 < 2*nn);
    cout << ans.size() - 1 << endl;
    for (size_t i = 0; i < ans.size(); ++i){
        cout << ans[i].F << " " << ans[i].S << endl;
    }
    return 0;
}
