/****************************************
**        Solution by NU PTZ 2016      **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, d, a, b;
int p[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    int n, d[300100];
    scanf("%i", &n);
    for (int i = 0; i < n; i++){
        scanf("%i", &d[i]);
    }
    int i = 0; 
    vector<pair<int, int> > ans;
    while (i < n){
        int temp = 1;
        int j = i;
        while(j < n && temp <= d[j]){
            temp++;
            j++;
        }
        int lr = j-i;
        temp = d[i];
        j = i;
        while (j < n && temp > 0){
            temp--;
            j++;
            temp = min(temp, d[j]);
        }
        int rl = j-i;
        if (lr >= rl){
            ans.push_back(make_pair(i+1, i+lr));
            i = i+lr;
        }
        else{
            ans.push_back(make_pair(i+rl, i+1));
            i = i+rl;
        }
    }
    printf("%i\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++){
        printf("%i %i\n", ans[i].first, ans[i].second);
    }

    return 0;
}
