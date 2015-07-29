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
const int maxn = 6;
const int maxsum = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

set <int> dp[maxn];
int a[maxn], n;

string int_to_str(int n) {
    string res;

    while (n) {
        res += (n % 10) + '0';
        n /= 10;
    }

    reverse(all(res));

    return res;
}

int str_to_int(const string& s) {
    int res = 0;

    for (size_t i = 0; i < s.size(); i++) {
        res *= 10;
        res += s[i] - '0';
    }

    return res;
}

void update(int pos, int num) {
    string temp = int_to_str(num);

    sort(all(temp));
    
    //cout << "update " << temp << endl;

    do {
        num = str_to_int(temp);
        dp[pos].insert(num);
    //    cout << num << endl;
    } while (next_permutation(all(temp)));
    //cout << endl;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    dp[0].insert(0);

    for (int i = 0; i < n; i++) {
        for (set <int> :: iterator it = dp[i].begin(); it != dp[i].end(); it++) {
            update(i + 1, *it + a[i]);
        }
    }

    int ans = *max_element(all(dp[n]));

    printf("%d", ans);

    return 0;
}
