/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

int a[100100];
vector<pair<int, int>> v;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++){
        scanf("%i", &a[i]);        

    }
    for (int i = 0; i < n; i++){     
        int x;
        scanf("%i", &x);
        v.push_back(make_pair(a[i], x));               
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    priority_queue<int> q;
    long long sum = 0;
    for (int i = 1; i < n; i++){
        if (i%2 == 1){
            sum += 1ll*v[i].second;
            q.push(-v[i].second);
        }
        else{
            int temp = -q.top();
            if (temp < v[i].second){
                q.pop();
                q.push(-v[i].second);
                sum -= 1ll*temp;
                sum += 1ll*v[i].second;
            }
        }
    }
    printf(I64, sum);
    return 0;
}
