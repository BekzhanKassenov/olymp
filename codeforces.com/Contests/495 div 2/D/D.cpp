/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int t;
int cnt[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &t);
    int mxEven = -1;
    int mx = 0;
    for (int i = 1; i <= t; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;

        if (x > mx) {
            mx = x;
        }
        if (x % 2 == 0 && x > mxEven) {
            mxEven = x;
        }
    }

    if (mxEven == -1) {
        cout << -1 << endl;
        return 0;
    }

    int I = mxEven / 2;
    int J = I + mx - mxEven;

    cout << I << ' ' << J << endl;
    cout << mx << ' ' << mxEven << endl;

    for (int i = 0; i <= I; i++) {
        for (int j = 0; j <= J; j++) {
            int dist = I - i + J - j;
            if (cnt[dist] == 0) {
                cout << -1 << endl;
                return 0;
            }
            cnt[dist]--;
        }
    }

    auto solve = [&](int N, int M) {

        int NI = I - (N - I) + 1;
        int MJ = J - (M - J) + 1;

        if (NI < 0 || MJ < 0) {
            return;
        }

        bool can = true;

        auto update = [&](int si, int ei, int sj, int ej, int delta) {
            for (int i = si; i <= ei; i++) {
                for (int j = sj; j <= ej; j++) {
                    int dist = I - i + J - j;
                    cnt[dist] += delta;
                    if (cnt[dist] < 0) {
                        can = false;
                    }
                }
            }
        };

        update(0, I, MJ, J - 1, -1);
        update(NI, I - 1, 0, J, -1);
        update(NI, I - 1, MJ, J - 1, -1);


        update(0, I, MJ, J - 1, 1);
        update(NI, I - 1, 0, J, 1);
        update(NI, I - 1, MJ, J - 1, 1);

        if (can) {
            cout << N << ' ' << M << endl;
            cout << I + 1 << ' ' << J + 1 << endl;
            exit(0);
        }
    };

    for (int N = 1; N * N <= t; N++) {
        if (t % N != 0) {
            continue;
        }

        int M = t / N;
        if (I >= N || J >= M) {
            continue;
        }

        solve(N, M);
        solve(M, N);
    }

    cout << -1 << endl;
    
    return 0;
}
