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
#define File "frontier"

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


int n, a[maxn], l1[maxn], r1[maxn], l2[maxn], r2[maxn], tot1, tot2;

void up(int x, int *v, int val){
    for (int i = x; i < maxn; i += (i&(-i)))
        v[i]+= val;
}
int get(int x, int *v){
    int res = 0;
    for (int i = x; i > 0; i -= (i&(-i)))
        res += v[i];
    return res;
}
void compress() {
    map <int, int> Map;
    vector <int> temp;
    
    for (int i = 0; i < n; i++) {
        temp.push_back(a[i]);
    }
    
    sort(all(temp));
    
    temp.resize(unique(all(temp)) - temp.begin());
    
    if ((int)temp.size() < n) {
        cout << "YES";
        exit(0);
    }
    
    for (int i = 0; i < n; i++) {
        Map[temp[i]] = i + 1;
    }
    
    for (int i = 0; i < n; i++)
        a[i] = Map[a[i]];
        
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    
    compress();
    
    
    bool cur = 0;
    
    for (int i = 0; i < n - 1; i++) {
        
        int l = a[i], r = a[i + 1];
        
        if (l > r)
            swap(l, r);
        if (!cur){
            if (get(l, l1) != get(r, l1)){
                cout << "YES";
                return 0;
            }
            up(l, l1, 1);
            up(r, l1, -1);
             
        }
        else {
            if (get(l, l2) != get(r, l2)){
                cout << "YES";
                return 0;
            }
            up(l, l2, 1);
            up(r, l2, -1);
             
        }
        cur ^= 1;
    }
    
    cout << "NO";
    return 0;
}
