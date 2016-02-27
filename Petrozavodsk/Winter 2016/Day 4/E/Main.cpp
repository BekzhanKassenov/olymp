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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a, b;

int getLCA(int a, int b) {
    set <int> setA;
    while (a > 0) {
        setA.insert(a);
        a /= 2;
    }

    while (b > 0) {
        if (setA.count(b)) {
            return b;
        }

        b /= 2;
    }

    return 1;
}

vector <int> getPath(int a, int l) {
    vector <int> ans;
    while (a != l) {
        ans.push_back(a);
        a /= 2;
    }

    return ans;
}

void restore(const vector <int>& vecA, vector <int>& ans) {
    for (size_t i = 1; i < vecA.size(); i++) {
        if (2 * vecA[i] == vecA[i - 1]) {
            ans.push_back(2 * vecA[i] + 1);
        } else {
            ans.push_back(2 * vecA[i]);
        }
    }
}   

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &a, &b);

    int l = getLCA(a, b);

    if (l == a || l == b) {
        puts("-1");
        return 0;
    }

    vector <int> vecA = getPath(a, l);
    vector <int> vecB = getPath(b, l);
    vector <int> vecL = getPath(l, 1);

    if (l != 1) {
        vecL.push_back(1);
    }

    vector <int> ans;

    restore(vecA, ans);
    restore(vecB, ans);
    restore(vecL, ans);

    ans.push_back(a);
    ans.push_back(b);

    sort(all(ans));

    for (int x: ans) {
        printf("%d ", x);
    }
    puts("");
    
    return 0;
}
