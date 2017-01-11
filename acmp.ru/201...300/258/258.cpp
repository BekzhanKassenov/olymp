#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int val(int k, int x) {
    if (k % x == 0) {
        return x;
    }

    return k % x;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k1, m, k2, p2, n2;
    cin >> k1 >> m >> k2 >> p2 >> n2;

    if (n2 > m) {
        puts("-1 -1");
        return 0;
    }

    vector <int> ansvec;
    for (int x = 1; x <= 2017; x++) {
        if (m * x * (p2 - 1) + x * (n2 - 1) + val(k2, x) == k2) {
            ansvec.push_back(x);
        }
    }

    int p1 = -1, n1 = -1;
    for (int ans : ansvec) {
        int totalFloors = (k1 + ans - 1) / ans;
        int tp1 = totalFloors / m - (totalFloors % m == 0) + 1;
        int tn1 = val(totalFloors, m);

        //cerr << ans << ' ' << totalFloors << ' ' << tp1 << ' ' << tn1 << endl;

        if (p1 == -1) {
            p1 = tp1, n1 = tn1;
        } else {
            if (p1 != 0 && tp1 != p1) {
                p1 = 0;
            }
            if (n1 != 0 && tn1 != n1) {
                n1 = 0;
            }
        }
    }

    printf("%d %d\n", p1, n1);

    return 0;
}
