#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

void factor(map <int, int>& divs, int n) {
    int k = sqrt(n + .0) + 1;

    for (int i = 2; i <= k; i++) {
        while (n % i == 0) {
            divs[i]++;
            n /= i;
        }
    }

    if (n > 1)
        divs[n]++;
}

int n, m, ans;
map <int, int> divs_n, divs_m;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    factor(divs_n, n);
    factor(divs_m, m);

    for (map <int, int> :: iterator it = divs_m.begin(); it != divs_m.end(); it++) {
        ans += abs(it -> second - divs_n[it -> first]);
        divs_n.erase(divs_n.find(it -> first));
    }

    for (map <int, int> :: iterator it = divs_n.begin(); it != divs_n.end(); it++) {
        ans += it -> second;
    }

    printf("%d", ans);

    return 0;
}