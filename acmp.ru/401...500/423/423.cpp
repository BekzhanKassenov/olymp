#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 110;

char s[maxn];
int n, calced[maxn];

struct BigInt {
    vector <int> dig;
    
    BigInt() {
        dig.push_back(0);
    }

    void operator += (const BigInt& rhs) {
        int flag = 0;

        for (size_t i = 0; i < dig.size(); i++) {
            flag += dig[i];

            if (i < rhs.dig.size())
                flag += rhs.dig[i];

            dig[i] = flag % 10;
            flag /= 10;
        }

        for (size_t i = dig.size(); i < rhs.dig.size(); i++) {
            flag += rhs.dig[i];

            dig.push_back(flag % 10);
            flag /= 10;
        }

        while (flag) {
            dig.push_back(flag % 10);
            flag /= 10;
        }
    }

    void print() {
        for (int i = dig.size() - 1; i >= 0; i--)
            printf("%d", dig[i]);
    }
};

BigInt dp[maxn];

inline bool ok(int l, int r) {
    if (s[l] == '0')
        return r == l;

    int num = 0;

    for (int i = l; i <= r; i++) {
        num *= 10;                        
        num += s[i] - '0';
    }

    return num <= 33;
}

void solve(int pos) {
    if (pos >= n) {
        dp[pos].dig[0] = 1;
        return;
    }

    if (calced[pos])
        return;

    calced[pos] = true;

    for (int i = pos; i < n && ok(pos, i); i++) {
        solve(i + 1);
        dp[pos] += dp[i + 1];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);
    n = strlen(s);

    solve(0);

    dp[0].print();

    return 0;
}
