#include <iostream>
#include <cstdio>
#include <cassert>
#include <unordered_map>
#include <set>

using namespace std;

int n, m;
unordered_map <int, int> tree;
char type;
int num;

void update(int pos) {
    for (int i = pos; i <= n; i |= i + 1) {
        tree[i]++;
    }
}

int sum(int pos) {
    int ans = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        if (tree.count(i)) {
            ans += tree[i];
        }
    }

    return ans;
}

set <int> erased;

int query(int num) {
    int l = 1, r = n;

    while (l <= r) {
        int mid = (l + r) / 2;

        int f = mid - sum(mid - 1);

        if (f == num && !erased.count(mid)) {
            return mid;
        }

        if (f <= num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    assert(false);
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE        
	freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);

    while (m--) {
        scanf("%c %d\n", &type, &num);

        if (type == 'D') {
            int val = query(num);
            update(val);
            erased.insert(val);
        } else {
            printf("%d\n", query(num));
        }
    }

	return 0;
}
