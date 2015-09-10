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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char type[MAXN];
int val[MAXN];
long long sum;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d\n", &n);

    for (int i = 2; i <= n; i++) {
        scanf("%c%d\n", &type[i], &val[i]);
    }

    priority_queue <pair <int, int> , vector <pair <int, int> >, greater <pair <int, int> > > q;

    for (int i = 2; i < n; i++) {
        if (type[i] == 'd') {
            q.push(make_pair(val[i], i));
            sum += val[i];
        } else {
            while ((int)q.size() >= val[i]) {
                sum -= q.top().first;
                q.pop();
            }
        }
    }

    if ((int)q.size() < val[n]) {
        puts("-1");
        return 0;
    }

    printf("%I64d\n%u\n", sum, q.size());

    vector <int> vec;
    while (!q.empty()) {
        vec.push_back(q.top().second);
        q.pop();
    }

    sort(all(vec));
    for (int it: vec) {
        printf("%d ", it);
    }

    puts("");

    return 0;
}
