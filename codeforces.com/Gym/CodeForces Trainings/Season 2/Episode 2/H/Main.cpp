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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

string s;
vector <long long> nums;
vector <char> sign;
ll dp_min[MAXN][MAXN];
ll dp_max[MAXN][MAXN];
bool calced_min[MAXN][MAXN];
bool calced_max[MAXN][MAXN];

long long get_min(int l, int r) {
    if (l == r)
        return nums[l];
    
    if (calced_min[l][r])
        return dp_min[l][r];

    calced_min[l][r] = true;
    ll& ans = dp_min[l][r];
    ans = -1;

    for (int i = l; i < r; i++) {
        ll left = get_min(l, i);
        ll right = get_min(i + 1, r);

        ll res;
        if (sign[i] == '+')
            res = left + right;
        else
            res = left * right;

        if (ans == -1 || res < ans)
            ans = res;
    }

    return ans; 
}

long long get_max(int l, int r) {
    if (l == r)
        return nums[l];

    if (calced_max[l][r])
        return dp_max[l][r];

    calced_max[l][r] = true;
    ll& ans = dp_max[l][r];
    ans = -1;

    for (int i = l; i < r; i++) {
        ll left = get_max(l, i);
        ll right = get_max(i + 1, r);

        ll res;
        if (sign[i] == '+')
            res = left + right;
        else
            res = left * right;

        if (ans == -1 || res > ans)
            ans = res;
    }

    return ans; 
}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    while (getline(cin, s) && s != "END") {
        nums.clear();
        sign.clear();

        int n; 
        char c;
        stringstream ss(s);
        ss >> n;
        nums.push_back(n);

        while (ss >> c >> n) {
            sign.push_back(c);
            nums.push_back(n);
        }

        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < nums.size(); j++) {
                calced_min[i][j] = false;
                calced_max[i][j] = false;
            }
        }

        printf("%I64d %I64d\n", get_min(0, nums.size() - 1), get_max(0, nums.size() - 1));
    }

    return 0;
}
