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

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 9;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int N, K;
int arr[26][1000010];

/*int get(int t[], int pos) {
    int res = 0;
    
    for (int i = pos; i > 0; i -= i&(-i)) {
        res += t[i];
        res %= MOD;
    }
    
    return res;
}

void upd(int t[], int pos, int val) {
    
    for (int i = pos; i <= N; i += i&(-i)) {
        t[i] += val;
        t[i] %= MOD;
    }
}*/

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++)
        arr[1][i] = i;
        
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            int res = arr[i - 1][j / 2];
            arr[i][j] = res;
        }
        
        for (int j = 1; j <= N; j++) {
            arr[i][j] += arr[i][j - 1];
            arr[i][j] %= MOD;
        }
    }
    
    /*for (int i = 1; i <= K; ++i){
        for (int j = 1; j <= N; ++j)
            cout << get(arr[i], j) - get(arr[i], j-1) << " ";
            cout << endl;
    }*/
    
    cout << (arr[K][N] - arr[K][N - 1] + MOD) % MOD;
    
    return 0;
}
