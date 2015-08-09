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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
char input[MAXN * 11];
bool bad[MAXN];
int a[MAXN];

void fill(vector <int>& vec, int l, int r) {
    if (vec[l] >= vec[r]) {
        puts("Incorrect sequence");
        exit(0);
    }

    if (vec[r] - vec[l] < r - l) {
        puts("Incorrect sequence");
        exit(0);
    }

    if (vec[l] >= 0 && vec[r] >= 0) {
        for (int i = l + 1; i < r; i++) {
            vec[i] = vec[i - 1] + 1;
        }
    } else if (vec[l] <= 0 && vec[r] <= 0) {
        for (int i = r - 1; i > l; i--) {
            vec[i] = vec[i + 1] - 1;
        }
    } else {
        int _left = -1, _right = 1;
        vector <int> temp;
        temp.push_back(0);

        for (int i = 0; i < r - l - 2; i++) {
            if (_left > vec[l]) {

            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &k);
    gets(input);

    int last = 0;
    bool flag = false;

    for (int i = 0; input[i]; i++) {
        if (input[i] == '?') {
            bad[last] = true;
        } else if (input[i] == '-') {
            flag = true;
        } else if (isdigit(input[i])) {
            a[last] *= 10;
            a[last] += input[i] - '0';
        } else {
            if (flag) {
                a[last] *= -1;
            }

            last++;
            flag = false;
        }
    }

    for (int i = 0; i < k; i++) {
        vector <int> temp;
        temp.push_back(-INF);

        for (int j = i; j < n; j += k) {
            temp.push_back(a[j]);
        }

        temp.push_back(INF);

        // fill

        for (int j = i; j < n; j += k) {
            a[j] = temp[j / k];
        }
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    puts("");

    return 0;
}
