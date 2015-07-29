#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("out", "w", stdout);
    for (int n = 1; n <= 10; n++) {
        //cout << n << ' ';
        for (int k = 1; k <= 4; k++) {
            vector <int> a(n);

            for (int i = 0; i < n; i++)
                a[i] = i;

            int res = 0;

            do {
                bool flag = true;
                for (int i = 1; i < n; i++)
                    if (abs(a[i] - a[i - 1]) > k)
                        flag = false;
                res += flag;
            } while (next_permutation(a.begin(), a.end()));

            cout << res << ' ';
        }
        cout << endl;
    }
}
