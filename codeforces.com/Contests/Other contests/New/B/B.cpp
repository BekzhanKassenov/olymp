/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int MAXK = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, ans;
int mem[MAXK], a[MAXN];
map <int, int> cnt, pos;
vector <int> available;

void add(int num, int position) {
    pos.erase(mem[position]);
    mem[position] = num;
    pos[num] = position;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    for (int i = 0; i < k; i++) {
        available.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (!pos.count(a[i])) {
            ans++;

            if (!available.empty()) {
                add(a[i], available.back());
                available.pop_back();
            } else {
                add(a[i], 0);
            }
        }

        cnt[a[i]]--;
        if (cnt[a[i]] == 0) {
            available.push_back(pos[a[i]]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
