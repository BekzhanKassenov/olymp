#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }

const int MAXN = 510;

struct Segment {
    int from, to;
    int num;

    bool contains(const Segment& s) const {
        return from < s.from && s.to < to;
    }
};

int n;
Segment segm[MAXN];
int dp[MAXN];
int nxt[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &segm[i].from, &segm[i].to);
        segm[i].num = i + 1;
        dp[i] = 0;
        nxt[i] = -1;
    }

    sort(segm, segm + n, by(Segment, from));

    int mxpos = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (dp[i] < dp[j] + 1 && segm[i].contains(segm[j])) {
                dp[i] = dp[j] + 1;
                nxt[i] = j;
            }
        }

        if (dp[i] > dp[mxpos]) {
            mxpos = i;
        }
    }

    vector <int> ans;
    for (int pos = mxpos; pos != -1; pos = nxt[pos]) {
        ans.push_back(segm[pos].num);
    }

    reverse(all(ans));

    printf("%lu\n", ans.size());
    for (int x: ans) {
        printf("%d ", x);
    }

    puts("");

    return 0;
}
