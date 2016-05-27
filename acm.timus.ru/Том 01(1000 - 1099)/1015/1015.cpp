#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

/*
    {1, 0, 2, 3, 4, 5},
    {0, 1, 4, 3, 2, 5},
    {0, 1, 2, 5, 4, 3}
*/

const int rot[3][6] = {
    {3, 5, 2, 1, 4, 0},
    {0, 1, 3, 4, 5, 2},
    {4, 2, 0, 3, 1, 5},
};

vector <int> apply(const vector <int>& vec, const int p[]) {
    vector <int> temp(6);

    for (int i = 0; i < 6; i++) {
        temp[p[i]] = vec[i];
    }

    return temp;
}

int pack(const vector <int>& a) {
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        ans *= 10;
        ans += a[i];
    }

    return ans;
}

set <int> used;

int dfs(const vector <int>& v) {
    int num = pack(v);
    used.insert(num);
    
    int ans = num;
    for (int i = 0; i < 3; i++) {
        vector <int> nxt(apply(v, rot[i]));
        
        if (!used.count(pack(nxt))) {
            ans = min(ans, dfs(nxt));
        }
    }

    return ans;
}

int n;
map <int, vector <int> > ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        vector <int> vec(6);

        for (int j = 0; j < 6; j++) {
            scanf("%d", &vec[j]);
        }

        int q = dfs(vec);
        ans[q].push_back(i);
        used.clear();
    }

    vector <vector <int> > res;
    for (const auto& it: ans) {
        res.emplace_back(it.second);
    }

    sort(res.begin(), res.end(), [](const vector <int>& a, const vector <int>& b) {
        return a[0] < b[0];
    });

    printf("%d\n", (int)res.size());

    for (const auto& v: res) {
        for (size_t i = 0; i < v.size(); i++) {
            printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
        }
    }

    return 0;
}
