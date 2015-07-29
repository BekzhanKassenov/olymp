#include <cstdio>
#include <map>

using namespace std;

const int BASE = 1000 * 1000;

int n;

map <int, int> Map;

inline int hash(int a, int b) {
    return a * BASE + b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    int cur = 10;

    for (int pos = 0; ; pos++) {
        int rem = 0;

        if (cur >= n) {
            rem = cur / n;
            cur %= n;
        }

        int h = hash(cur, rem);
        if (Map.count(h)) {
            int prev = Map[h];

            printf("%d %d\n", prev, pos - prev);
            
            return 0;
        }

        if (pos < 1000) {
            Map[hash(cur, rem)] = pos;
        }

        cur *= 10;
    }

    return 0;
}
