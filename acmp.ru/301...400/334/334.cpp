#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 50010;

int read() {
    int h, m, s;

    scanf("%d:%d:%d", &h, &m, &s);
    
    h--;

    return h * 60 * 60 + m * 60 + s;
}

void print(int ss) {
    int s = ss % 60;
    ss /= 60;
    
    int m = ss % 60;
    ss /= 60;
    
    int h = ss;

    h++;

    printf("%d:%02d:%02d", h, m, s);
}

int n, a[maxn], ans;
ll mins = maxn * 1ll * maxn, sum[maxn];

int get_lower(int tim) {
    int l = 1, r = n, ans = 1;

    if (a[l] >= tim)
        return 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (a[mid] < tim) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int get_upper(int tim) {
    int l = 1, r = n, ans = 1;

    if (a[r] <= tim)
        return n + 1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (a[mid] > tim) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        a[i] = read();

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];


    for (int tim = 0; tim < 12 * 60 * 60; tim++) {
        int posl = get_lower(tim);
        int posr = get_upper(tim);

        ll cntl = posl;
        ll cntr = n - posr + 1;

        ll sm = cntl * tim - sum[posl];
        sm += (12 * 60 * 60 * cntr - (sum[n] - sum[posr - 1])) + tim * cntr;

        if (sm < mins) {
            mins = sm;
            ans = tim;
        }
    }

    print(ans);

    return 0;
}
