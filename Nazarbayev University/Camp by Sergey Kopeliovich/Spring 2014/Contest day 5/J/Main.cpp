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
#define File "tickets"

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

int a[6];
int cost[6] = {10, 50, 100, 500, 1000, 5000};
int tick, sum;

bool check(int n) {
    int tot_cost = tick * n;
    
    for (int i = 0; i < 6; i++) {
        if (a[i] > 0) {
            int cur_cost = 0;
            
            for (int j = 0; j < 6; j++) {
                if (j != i)
                    cur_cost += cost[j] * a[j];
                else
                    cur_cost += cost[j] * (a[j] - 1);
            }
            
            if (cur_cost >= tot_cost)
                return false;
        }
    }
    
    return true;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    for (int i = 0; i < 6; i++)
        cin >> a[i];
        
    cin >> tick;
        
    for (int i = 0; i < 6; i++) {
        sum += a[i] * cost[i];
    }
    
    vector <int> res;
    
    for (int i = 0; i * tick <= sum; i++)
        if (check(i))
            res.push_back(i);
    
    cout << res.size() << endl;
    
    for (size_t i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}
