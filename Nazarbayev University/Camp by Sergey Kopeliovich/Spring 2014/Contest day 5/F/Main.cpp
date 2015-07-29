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
#define File "mouse"

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

int n;
bool dp[1001][101][101];
vector<int> ans;
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n;
    int len = 0;
    for (int i = 0; i < 101; ++i){
        dp[0][i][i] = 1;
    }
    bool found = 1;
    set<int> v;
    while (found){
        found = 0;
        v.clear();
        bool dont = 0;
        int mx = 0, index = rand()%n;
      /* for (int i = 0; i < n; ++i){
            int was = -1;
            for (int j = 0; j < n; ++j){
                if (dp[len][j][i]){
                    if (was == -1){
                        was = j;
                    }
                    else {
                        was = -1;
                        break;
                    }
                }
            }
            if (was != -1)
                v.insert(was);
        }
     */
        for (int i = 0; i < n && !found; ++i){
            int cnt = 0;
            for (int j = 0; j < n && !found; ++j){
                if (dp[len][i][j])
                    found = 1;
                    
            }/*
            if (cnt > mx){
                mx = cnt;
                index = i;
                found = 1;
            }
            else if (cnt == mx && !v.empty() && !dont){
                if (v.count(i)){
                    index = i;
                    dont = 1;
                }
            }
            else if (cnt == mx && i > 0 && i < n-1 && !dont)
                index = i;*/
        }
        if (found){
            for (int i = 0; i < n; ++i)
                dp[len][index][i] = 0;    
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    if (dp[len][i][j]){
                        if (i > 0)
                            dp[len+1][i-1][j] = 1;
                        if (i < n-1)
                            dp[len+1][i+1][j] = 1;
                    }
                }
            }
            ans.push_back(index+1);
           /* for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    cout << dp[len][i][j];
                    
                }
                cout << endl;
            }
            cout << endl;
             */
        }
        
//        cerr << "ASD" << endl;
        len++;
    }
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
    return 0;
}
