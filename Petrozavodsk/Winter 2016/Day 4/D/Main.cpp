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
const int N = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q, l, r;
int p[N], c[N], pn[N], cn[N], cnt[N], classes, cl[N][20];
int lg2[N];
char s[N];

bool compare(int l1, int r1, int l2, int r2) {
    
    cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    int len = r1 - l1 + 1;
    int h = lg2[len];

    if(cl[l1][h] != cl[l2][h] || cl[r1 - (1 << h) + 1][h] != cl[r2 - (1 << h) + 1][h]) return false;
    return true;
} 
int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d\n", &n, &q);
    gets(s);
    s[n] = '$';
    n++;

    for(int i = 2; i <= n; i++)
        lg2[i] = lg2[i >> 1] + 1;  
    
    for(int i = 0; i < n; i++)
        cnt[s[i]]++;

    for(int i = 0; i <= 'z'; i++)
        cnt[i] += cnt[i - 1];

    for(int i = n - 1; i >= 0; i--)
        p[--cnt[s[i]]] = i;

    for(int i = 0; i < n; i++) {
        if(s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes;
        cl[p[i]][0] = classes;
    }

    for(int h = 0; (1 << h) <= n; h++) {

        for(int i = 0; i < n; i++) {
            int tmp = p[i] - (1 << h);
            if(tmp < 0) tmp += n;
            pn[i] = tmp;
        }

        memset(cnt, 0, n * sizeof(int));

        for(int i = 0; i < n; i++) {
            cnt[c[pn[i]]]++;
        }
        for(int i = 1; i <= classes; i++)
            cnt[i] += cnt[i - 1];

        for(int i = n - 1; i >= 0; i--) {
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        cn[p[0]] = 0;
        classes = 0;
        for(int i = 1; i < n; i++) {
            int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
            if(c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2])  classes++;
            cn[p[i]] = classes;
        }

        memcpy(c, cn, n * sizeof(int));
        for(int i = 0; i < n; i++)
            cl[p[i]][h + 1] = c[p[i]];
    }

    int ll, rr;

    for(int i = 0; i < 1; i++) {
        scanf("%d%d", &ll, &rr);

        ll--;
        rr--;

        l = ll - 1; 
        r = rr + 1;

        while(r - l > 1) {
            int mid = (l + r) / 2;
            cout << mid << " ";
            if(compare(ll, ll + mid - 1, rr - mid + 1, rr)) l = mid; else r = mid;
        }
        cout << r << endl;
    }
    return 0;
}
