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

#define left asdasdas
#define right asdasdasdasd

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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int left_a[maxn], left_b[maxn], left_c[maxn];
int right_a[maxn], right_b[maxn], right_c[maxn];
int last[3], n;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    string s, t;
    
    cin >> s >> t;
    
    n = s.size();
    
    last[0] = last[1] = last[2] = -1;
    
    for (int i = n - 1; i >= 0 && last[0] == -1 && last[1] == -1 && last[2] == -1; i--) {
        if (last[s[i] - 'a'] == -1) {
            last[s[i] - 'a'] = n - i - 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        last[s[i] - 'a'] =  -1;
                 
        for (int j = 0; j < 3; j++)
            last[j]++;
            
        left_a[i] = last[0];
        left_b[i] = last[1];
        left_c[i] = last[2];
    }

    last[0] = last[1] = last[2] = -1;
    
    for (int i = 0; i < n && last[0] == -1 && last[1] == -1 && last[2] == -1; i++) {
        if (last[s[i] - 'a'] == -1) {
            last[s[i] - 'a'] = i;
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        last[s[i] - 'a'] = -1;
        
        for (int j = 0; j < 3; j++)
            last[j]++;
            
        right_a[i] = last[0];
        right_b[i] = last[1];
        right_c[i] = last[2];
    }
    
    int left[3] = {0, 0, 0}, right[3] = {0, 0, 0};
    
    for (int i = 0; i < n; i++) {
        if (t[i] == '*') {
            left[0] = max(left[0], left_a[i]);
            left[1] = max(left[1], left_b[i]);
            left[2] = max(left[2], left_c[i]);
            
            right[0] = max(right[0], right_a[i]);
            right[1] = max(right[1], right_b[i]);
            right[2] = max(right[2], right_c[i]);
        }
    }
    
    int ans = INF;

    for (int mask = 0; mask < (1 << 3); mask++) {
        int move_l = 0, move_r = 0;
        
        for (int i = 0; i < 3; i++) {
            if (mask & (1 << i)) {
                move_l = max(move_l, left[i]);
            } else {
                move_r = max(move_r, right[i]);
            }
        }
        
        ans = min(ans, 2 * min(move_l, move_r) + max(move_l, move_r));
    }
    
    cout << ans << endl;
    
    return 0;
}
