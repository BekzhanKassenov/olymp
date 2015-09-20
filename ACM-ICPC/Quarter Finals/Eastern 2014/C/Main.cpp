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
const int MAXN = 1000010;
const int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x;

int convert(int day, int month, int hour, int minute) {
    int ans = 0;
    for (int i = 0; i < month; i++) {
        ans += months[i];
    }

    ans += day;

    ans *= 24;
    ans += hour;
    ans *= 60;
    ans += minute;

    return ans;
}

/* =================== Letter =====================*/ 

struct Letter {
    int delta;
    int moment;
    int num;
    int treePos;
    char sign;
};  

Letter a[MAXN];

bool cmpTime(const Letter& l1, const Letter& l2) {
    return l1.moment < l2.moment;
}

bool cmpPos(const Letter& l1, const Letter& l2) {
    return l1.num < l2.num;
}

/* =================== Fenwick =====================*/

int last;
long long arr[MAXN];
long long t[4 * MAXN];

void update(int v, int l, int r, int pos, int val) {
    if (pos < l || pos > r) {
        return;
    }

    if (l == r) {
        arr[l] += val;

        if (arr[l] < 0) {
            t[v] = arr[l];
        } else {
            t[v] = 0;
        }

        return;
    }

    int mid = (l + r) / 2;
    update(2 * v, l, mid, pos, val);
    update(2 * v + 1, mid + 1, r, pos, val);

    t[v] = t[2 * v] + t[2 * v + 1];
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        int delta, day, month, hour, minute;

        scanf("%d %d.%d %d:%d", &delta, &day, &month, &hour, &minute);

        a[i].delta = delta;
        a[i].moment = convert(day, month, hour, minute);
        a[i].num = i;

        if (a[i].delta < 0) {
            a[i].sign = '-';
        } else {
            a[i].sign = '+';
        }
    }

    sort(a, a + n, cmpTime);

    char lastDelta = '+';

    for (int i = 0; i < n; i++) {
        if (a[i].sign == lastDelta) {
            a[i].treePos = last;
        } else if (a[i].sign == '+') {
            last++;

            a[i].treePos = last;
        }

        lastDelta = a[i].sign;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i].moment << ' ' << a[i].sign << endl;
    }

    last++;
    sort(a, a + n, cmpPos);

    for (int i = 0; i < n; i++) {
        update(1, 0, last - 1, a[i].treePos, a[i].delta);

        printf("%I64d\n", t[1]);
    }

    return 0;
}
