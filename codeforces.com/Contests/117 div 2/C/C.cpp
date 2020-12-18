/*********************************************
**       Solution by Bekzhan Kasenov        **
**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>

using namespace std;

const int MAXN = 100010;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000;

struct Sum {
    int k;
    multiset <int> kmax;
    long long kmaxsum = 0;
    multiset <int> rest;
    long long restsum = 0;

    Sum(int k) : k(k) {}

    void rm_kmax(multiset<int>::iterator it) {
        kmaxsum -= *it;
        kmax.erase(it);
    }

    void rm_rest(multiset<int>::iterator it) {
        restsum -= *it;
        rest.erase(it);
    }

    void add_kmax(int num) {
        kmax.insert(num);
        kmaxsum += num;
    }

    void add_rest(int num) {
        rest.insert(num);
        restsum += num;
    }

    void add(int num) {
        if (k == 0) {
            add_rest(num);
            return;
        }
        if ((int)kmax.size() < k) {
            add_kmax(num);
            return;
        }
        auto mn = kmax.begin();
        int mnval = *mn;
        if (num > mnval) {
            rm_kmax(mn);
            add_rest(mnval);
            add_kmax(num);
        } else {
            add_rest(num);
        }
    }

    void rm(int num) {
        auto restit = rest.find(num);
        if (restit != rest.end()) {
            rm_rest(restit);
            return;
        }
        rm_kmax(kmax.find(num));
        if (!rest.empty()) {
            auto mx = --rest.end();
            int mxval = *mx;
            rm_rest(mx);
            add_kmax(mxval);
        }
    }
};

int n, len, k;
int a[MAXN];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

    cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> k;

    Sum pos(k), neg(k);

    for (int i = 1; i <= len; i++) {
        if (a[i] >= 0) {
            pos.add(a[i]);
        } else {
            neg.add(-a[i]);
        }
    }

    long long ans = -INF;

    auto solve = [&]() {
        long long posmax = pos.kmaxsum;
        long long posrest = pos.restsum;
        long long negmax = neg.kmaxsum;
        long long negrest = neg.restsum;

        long long S1 = abs(posmax + posrest - negmax - negrest);
        long long S2 = abs(-posmax + posrest - negmax - negrest);
        long long S3 = abs(posmax + posrest + negmax - negrest);

        ans = max(ans, max(S1, max(S2, S3)));
    };

    solve();
    for (int i = len + 1; i <= n; i++) {
        if (a[i] >= 0) {
            pos.add(a[i]);
        } else {
            neg.add(-a[i]);
        }
        if (a[i - len] >= 0) {
            pos.rm(a[i - len]);
        } else {
            neg.rm(-a[i - len]);
        }
        solve();
    }

    cout << ans << endl;


	return 0;
}
