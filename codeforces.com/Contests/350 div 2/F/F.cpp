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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s[MAXN], t[MAXN];
char ans[MAXN], buf[MAXN];
char buf1[MAXN], buf2[MAXN], buf3[MAXN];
char buf4[MAXN], buf5[MAXN], buf6[MAXN]; 
int cnt[10];

bool basic_check(int len) {
    static int mcnt[10];
    memset(mcnt, 0, sizeof mcnt);

    int ll = 0;
    int cp = len;
    while (len > 0) {
        mcnt[len % 10]++;
        len /= 10;
        ll++;
    }

    for (int i = 0; i < 10; i++) {
        if (mcnt[i] > cnt[i]) {
            return false;
        }
    }

    return ll + cp == n && cp >= m;
}

void insert(int pos, char dest[], int lend, char src[], int lens) {
    for (int i = lend - 1; i >= pos; i--) {
        dest[i + lens] = dest[i];
    }

    for (int i = pos; i < pos + lens; i++) {
        dest[i] = src[i - pos];
    }

    dest[lend + lens] = '\0';
}

bool construct(int len) {
    static int mcnt[10];
    
    memcpy(mcnt, cnt, sizeof(mcnt));

    int ll = 0;
    while (len > 0) {
        mcnt[len % 10]--;
        len /= 10;
        ll++;
    }

    if (n == m + ll) {
        if (t[0] == '0' && m != 1) {
            return false;
        }

        strcpy(ans, t);
        return true;
    }

    int nonzero = -1;
    for (int i = 1; i < 10; i++) {
        if (mcnt[i] != 0) {
            nonzero = i;
            break;
        }
    }

    if (nonzero == -1) {
        if (t[0] == '0') {
            return false;
        }

        strcpy(ans, t);
        for (int i = m; mcnt[0]; i++) {
            ans[i] = '0';
            mcnt[0]--;
        }

        ans[strlen(ans)] = '\0';
        return true;
    }

    int pos = 0;
    buf[pos++] = nonzero + '0';
    mcnt[nonzero]--;

    for (int i = 0; i < 10; i++) {
        while (mcnt[i] > 0) {
            buf[pos++] = i + '0';
            mcnt[i]--;
        }
    }

    buf[pos] = '\0';

    int buflen = strlen(buf);
    int p1 = lower_bound(buf, buf + buflen, t[0]) - buf;    
    int p2 = upper_bound(buf, buf + buflen, t[0]) - buf;

    strcpy(buf1, buf);
    if (t[0] == '0') {
        insert(buflen, buf1, buflen, t, m);
    } else {
        insert(0, buf1, buflen, t, m);
    }

    strcpy(buf2, buf);
    insert(buflen, buf2, buflen, t, m);

    strcpy(buf3, buf);

    if (t[0] == '0' && p1 == 0) {
        insert(buflen, buf3, buflen, t, m);
    } else {
        insert(p1, buf3, buflen, t, m);
    }

    strcpy(buf4, buf);

    if (t[0] == '0' && p2 == 0) {
        insert(buflen, buf4, buflen, t, m);
    } else {
        insert(p2, buf4, buflen, t, m);
    }
    
    strcpy(buf5, buf);
    insert(1, buf5, buflen, t, m);

    vector <char*> vec = {&buf1[0], &buf2[0], &buf3[0], &buf4[0], &buf5[0]};
    sort(all(vec), [buflen](char* lhs, char* rhs) {
        int l = buflen + m;
        for (int i = 0; i < l; i++) {
            if (lhs[i] != rhs[i]) {
                return lhs[i] < rhs[i];
            }
        }

        return false;
    });

    strcpy(ans, vec[0]);
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);

    gets(t);
    m = strlen(t);

    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }

    for (int i = 0; i < m; i++) {
        cnt[t[i] - '0']--;
    }

    for (int added = 1; added < 10; added++) {
        int len = n - added;
        if (!basic_check(len)) {
            continue;
        }

        if (construct(len)) {
            puts(ans);
            return 0;
        }
    }

    return 0;
}
