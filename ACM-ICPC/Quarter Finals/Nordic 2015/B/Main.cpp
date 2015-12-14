/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define hash asdasdas

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int BASE = 9;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <vector <int> > res = {
    {1},
};

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int num = 2; num <= n; num++) {
        vector <vector <int> > temp;

        for (size_t i = 0; i < res.size(); i++) {
            if (i % 2 == 0) {
                for (int j = num - 1; j >= 0; j--) {
                    temp.push_back(res[i]);
                    temp.back().insert(temp.back().begin() + j, num);
                }
            } else {
                for (int j = 0; j < num; j++) {
                    temp.push_back(res[i]);
                    temp.back().insert(temp.back().begin() + j, num);
                }
            }
        }

        res.swap(temp);
    }

    for (const vector <int>& vec: res) {
        for (int num: vec) {
            printf("%d ", num);
        }

        puts("");
    }

    return 0;
}
