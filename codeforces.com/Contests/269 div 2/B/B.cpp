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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <int> deal[MAXN];
vector <int> ans[3];
int h, n;
bool flag;

void output() {
    puts("YES");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
}

bool test1() {
    for (int i = 0; i < MAXN; i++) {
        if (deal[i].size() >= 3u) {
            sort(deal[i].begin(), deal[i].begin() + 3);

            for (int j = 0; j < 3; j++) {
                ans[j].push_back(deal[i][0]);
                ans[j].push_back(deal[i][1]);
                ans[j].push_back(deal[i][2]);

                next_permutation(deal[i].begin(), deal[i].begin() + 3);
            }

            for (size_t j = 3; j < deal[i].size(); j++) {
                ans[0].push_back(deal[i][j]);
                ans[1].push_back(deal[i][j]);
                ans[2].push_back(deal[i][j]);
            }

            flag = true;
        } else {
            for (size_t j = 0; j < deal[i].size(); j++) {
                ans[0].push_back(deal[i][j]);
                ans[1].push_back(deal[i][j]);
                ans[2].push_back(deal[i][j]);
            }
        }
    }

    return flag;
}

bool test2() {
    int pos1 = -1, pos2 = -1;

    for (int i = 0; i < 3; i++)
        ans[i].clear();

    for (int i = 0; i < MAXN && (pos1 == -1 || pos2 == -1); i++) {
        if (deal[i].size() == 2u) {
            if (pos1 == -1)
                pos1 = i;
            else
                pos2 = i;
        }
    }

    if (pos1 == -1 || pos2 == -1)
        return false;

    for (int i = 0; i < MAXN; i++) {
        if (i == pos1) {
            ans[0].push_back(deal[i][0]);
            ans[0].push_back(deal[i][1]);
            
            ans[1].push_back(deal[i][0]);
            ans[1].push_back(deal[i][1]);

            ans[2].push_back(deal[i][1]);
            ans[2].push_back(deal[i][0]);
        } else if (i == pos2) {
            ans[0].push_back(deal[i][0]);
            ans[0].push_back(deal[i][1]);
            
            ans[1].push_back(deal[i][1]);
            ans[1].push_back(deal[i][0]);

            ans[2].push_back(deal[i][0]);
            ans[2].push_back(deal[i][1]);
        } else {
            for (size_t j = 0; j < deal[i].size(); j++) {
                ans[0].push_back(deal[i][j]);
                ans[1].push_back(deal[i][j]);
                ans[2].push_back(deal[i][j]);
            }
        }
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &h);
        deal[h].push_back(i + 1);
    }

    if (test1()) {
        output();
        return 0;
    }

    if (test2()) {
        output();
        return 0;
    }

    puts("NO");

    return 0;
}
