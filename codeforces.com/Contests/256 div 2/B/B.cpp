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
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[maxn], t[maxn], ns, nt;
int cnt[26];
                                         
bool can_aut() {
    if (ns < nt)
        return false;

    int pos = 0;

    for (int i = 0; i < ns; i++) {
        if (pos < nt && s[i] == t[pos])
            pos++;
    }

    return pos == nt;
}

bool can_both() {
    for (int i = 0; i < ns; i++)
        cnt[s[i] - 'a']++;

    for (int i = 0; i < nt; i++)
        cnt[t[i] - 'a']--;

    bool flag = true;

    for (int i = 0; i < 26; i++)
        flag &= (cnt[i] >= 0);

    return flag;
}

bool can_arr() {
    sort(s, s + ns);
    sort(t, t + nt);

    return strcmp(s, t) == 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    gets(s);
    ns = strlen(s);
    
    gets(t);
    nt = strlen(t);
    
    bool aut = can_aut();
    bool both = can_both();
    bool arr = can_arr();

    if (aut) {
        puts("automaton");
    } else if (arr) {
        puts("array");
    } else if (both) {
        puts("both");
    } else {
        puts("need tree");
    }

    return 0;
}
