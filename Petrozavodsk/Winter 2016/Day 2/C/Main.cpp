/****************************************
**          Solution by NU #2          **
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

    set<pair<int, int> > del;
    char c[1010];
    int a[1010];

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    int n;
    scanf("%i\n", &n);
    for (int i = 0; i < n; i++){
        scanf("%c %i\n", &c[i], &a[i]);
        if (c[i] == 'y') del.insert(make_pair(a[i], i));
    }
     
    int ans = 0;

    while (!del.empty()){
        ans++;
        int h = del.begin()->first;
        int idx = del.begin()->second;
//        cout << h << " ";

        del.erase(del.begin());
        c[idx] = 'n';
        a[idx] = 0;

        int temp = idx+1;
        while (temp < n && !(a[temp] >= h && c[temp] == 'n')){
            if (c[temp] == 'y'){
               // cout << a[temp] << " ";
                auto iter = del.find(make_pair(a[temp], temp));
                if (iter != del.end()) {
                    del.erase(iter);
                }
                c[temp] = 'n';
                a[temp] = 0;
            }
            temp++;
        }
        temp = idx-1;
        while (temp >= 0 && !(a[temp] >= h && c[temp] == 'n')) {
            if (c[temp] == 'y'){
                //cout << a[temp] << " ";
                auto iter = del.find(make_pair(a[temp], temp));
                if (iter != del.end()) {
                    del.erase(iter);
                }
                c[temp] = 'n';
                a[temp] = 0;
            }
            temp--;
        }
//        cout << endl;
    }
    printf("%i\n", ans);
    return 0;
}
