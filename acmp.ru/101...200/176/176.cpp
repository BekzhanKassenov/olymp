#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct BigInt {
    vector <int> vec;

    BigInt() { 
        vec.push_back(0);
    }

    BigInt(int n) {
        if (!n)
            vec.push_back(0);
        else {
            while (n) {
                vec.push_back(n % 10);
                n /= 10;
            }
        }
    }

    BigInt(const vector <int>& vec) : vec(vec) { } 

    BigInt(const BigInt& BI) : vec(BI.vec) { }
            
    static const BigInt ZERO;
    static const BigInt ONE;

    void trim() {
        while (!vec.empty() && vec.back() == 0)
            vec.pop_back();

        if (vec.empty())
            vec.push_back(0);
    }

    void operator += (const BigInt& bi) {
        int flag = 0;

        for (size_t i = 0; i < vec.size(); i++) {
            flag += vec[i];

            if (i < bi.vec.size())
                flag += bi.vec[i];

            vec[i] = flag % 10;
            flag /= 10;
        }

        for (size_t i = vec.size(); i < bi.vec.size(); i++) {
            flag += bi.vec[i];
            vec.push_back(flag % 10);
            flag /= 10;
        }

        while (flag) {
            vec.push_back(flag % 10);
            flag /= 10;
        }

        trim();
    }

    void operator -= (const BigInt& bi) {
        for (size_t i = 0; i < vec.size(); i++) {
            if (i < bi.vec.size()) {
                if (vec[i] < bi.vec[i]) {
                    vec[i] += 10;
                    vec[i + 1]--;
                }

                vec[i] -= bi.vec[i];
            } else {
                if (vec[i] < 0) {
                    vec[i] += 10;
                    vec[i + 1]--;
                }
            }
        }

        trim(); 
    }

    void print() {
        for (int i = vec.size() - 1; i >= 0; i--)
            printf("%d", vec[i]);

        puts("");
    }
};

const BigInt BigInt::ZERO(0);
const BigInt BigInt::ONE(1);
int n, k;
BigInt dp[110][55];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    dp[0][0] = BigInt::ONE;

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j + 1];

            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1];
        }
    }

    BigInt ans = dp[2 * n][0];

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = BigInt::ZERO;
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = dp[i - 1][j + 1];

            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1];
        }
    }

    ans -= dp[2 * n][0];
    ans.print();

    return 0;
}
